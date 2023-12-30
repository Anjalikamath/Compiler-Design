%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define YYSTYPE char*
#include "lex.yy.c"

void yyerror(const char *s);
int yylex();
extern int yylineno;
int curr_scope=0;
void display();


char st1[100][10];
char st[100][10];
int top=0;
int i_=0;
char si[20];

char temp[2]="t";

int label[20];
int lnum=0;
int ltop=0;
int start=1;
char ss[20];
char l[1]="L";
int top1=0;


void push();
void codegen();
void codegen_assign();
void codegen_umin();
void pushid(char*name);
void lab1();
void switch1();
void switch2();
void switch3();
void switch4();
void cse();

void my_itoa(int num,char temp1[20]);
void print_INT_CODE();
void print_OPT_CODE();
void copy_prop();
int isDigit(char t[100]);
void copy();
void labst();
void labw();
void labelend();
void lab2i();
void codep();
void codem();
void push1();
void push1id();
void remo();

struct OPT{
char op[10];
char arg1[10];
char arg2[10];
char result[10];
};

struct OPT QIC[100];
struct OPT OPT[100];
int ind=0;
int oind=0;


%}

%token T_If T_Print T_Do T_While T_Switch T_Else T_Case T_Id T_Int T_Float T_Double T_Eq T_Noteq T_Inc T_Dec T_Assignop T_Pluseq T_Shebang T_Minuseq T_Exp T_Lesseq T_Greteq T_Or T_And T_Not T_String T_True T_False T_Use T_Arr 

%left '>' '<' '=' T_Pluseq T_Minuseq
%left '+' '-' '*' '/' '%' ","
%left T_Inc T_Dec

%%
P : T_Shebang S
  ;

S: Declaration';'S
 | T_Do  opencurb {printf("\n");labst();} S  closecurb T_While openbrac  cond {printf("\n");labw();} closebrac ';' {printf("\n");} {labelend();}S 
 | us  S  T_Switch openbrac arg {printf("\n");switch1();} closebrac opencurb st closecurb S
 | T_Print T_String ';' S
 | T_Print openbrac T_String closebrac ';' S
 | T_Print openbrac T_Id closebrac ';' S
 | T_If openbrac cond closebrac{printf("\n");lab1();} opencurb S closecurb {printf("\n");lab2i();}S 
 | ue';'S
 | ArrayDecl ';' S
 | error S { yyerrok;yyclearin;  }
 | 
 ;

num:T_Int   {push();}
   |T_Float  {push();}
   |T_Double {push();}
   ;


ArrayDecl: T_Arr'=' openbrac closebrac 
         | T_Arr'='openbrac Di closebrac 
         ;
Di:num','Di
 |T_String','Di
 |num
 |T_String
 ;

Declaration:L
	   ;

L:L ',' X
 |X
 ;

X:T_Id  
 |Assign_expr
 ;
str:T_String {push();}
   ;

Assign_expr:T_Id{pushid($1);}'='{push();}E {codegen_assign();}
	   ;


cond:cond T_Or{push();} C {codegen();}
    |C
    ;

C: C T_And {push();} D{codegen();}
 |D
 ;

D:T_Not 
 |M
 ;

M:openbrac cond closebrac
 |relexp
 |T_True
 |T_False
 ;

relexp: relexp relop E {codegen();}
      |T_Id {push();}
      |num
      |str
      ;
relop: '<' {push();}
     |'>'  {push();}
     |T_Lesseq {push();}
     |T_Greteq  {push();}
     |T_Eq   {push();}
     |T_Noteq   {push();}
     ;

E:E'+'{push();} T  {codegen();}
  |E'-'{push();} T {codegen();}
  |E'.'{push();} T {codegen();}
  |T   
  |ue  //{codegen()}
  ;
T:T'*' {push();} F {codegen();}
 |T'/' {push();} F  {codegen();}
 |F
 ;
F:N T_Exp{push();} F {codegen();}
 |N
 ;
N:T_Id   {pushid($1);}
 |num  
 |str
 |'('E')'
 ;

ue:T_Id {pushid($1);}  T_Inc {codep();}
  |T_Id {pushid($1);} T_Dec {codem();}
  |T_Inc  T_Id {pushid($2);} {codep();}
  |T_Dec   T_Id {pushid($2);} {codem();}
  ;
us:T_Use T_Switch ';'  
  ;

arg:T_Id {push1id($1);}
   |T_Float {push1();}
   |T_Double {push1();}
   |T_Int {push1();}
   ;
st:T_Case Y O 
  ;
Y:K {switch2();} opencurb S closecurb {switch3();}
 ;
K:T_Int {push1(); switch1();} 
 |T_Float {push1(); switch1();}
 |T_Double {push1(); switch1();}
 |T_Id {push1id($1);switch1();}
 |T_String {push1();switch1();}
 ;
O:T_Else {printf("L%d:\n",lnum-1);}opencurb S closecurb {switch4();}
 |st
 ;
openbrac:'(' 
	;
closebrac:')' 
	 ;
opencurb:'{' 
	;
closecurb:'}' 
	 ;
%%



int main(int argc, char* *argv)
{	
	//printf("Enter a string\n");
	char ch,c;
	FILE *f;    
	if(argc != 2) {printf("useage:  calc filename \n"); exit(1);}
	if( !(yyin = fopen(argv[1],"r")) ){ 
	       printf("cannot open file\n");exit(1);
 }
	
	yyparse();

	printf("PARSING COMPLETE\n\n");
	
	print_INT_CODE();
	copy();
	copy_prop();
	remo();
	constant_folding();
	cse();
	print_OPT_CODE();

	display();

    
       
	return 0;
}

void yyerror(const char *s) {
 printf("\nError occured at %d\n ",yylineno);
 //printf("%d ",yyerrorstate);
 fprintf(stderr, "%s\n\n", s);

} 

void push(){
strcpy(st[++top],yytext);
}


void pushid(char*name){
strcpy(st[++top],name);
}

void push1()
{
	strcpy(st1[++top1],yytext);
}

void push1id(char*name){
	
	strcpy(st1[++top1],name);
}

void codep(){
strcpy(temp,"t");
my_itoa(i_,si);
strcat(temp,si);
char plus[1]="+";
strcpy(QIC[ind].result,temp);
strcpy(QIC[ind].op,plus);
strcpy(QIC[ind].arg1,st[top]);
strcpy(QIC[ind].arg2,"1");
ind++;

printf("%s = %s %s %d\n",temp,st[top],plus,1);
printf("%s=%s\n",st[top],temp);
i_++;
}


void codem(){
strcpy(temp,"t");
my_itoa(i_,si);
strcat(temp,si);
char plus[1]="-";
strcpy(QIC[ind].result,temp);
strcpy(QIC[ind].op,plus);
strcpy(QIC[ind].arg1,st[top]);
strcpy(QIC[ind].arg2,"1");
ind++;

printf("%s = %s %s %d\n",temp,st[top],plus,1);
printf("%s=%s\n",st[top],temp);
i_++;
}





void codegen(){
strcpy(temp,"t");
my_itoa(i_,si);
strcat(temp,si);
strcpy(QIC[ind].result,temp);
strcpy(QIC[ind].op,st[top-1]);
strcpy(QIC[ind].arg1,st[top-2]);
strcpy(QIC[ind].arg2,st[top]);
ind++;
printf("%s = %s %s %s\n",temp,st[top-2],st[top-1],st[top]);
top-=2;
strcpy(st[top],temp);
i_++;
}



void codegen_umin()
{
strcpy(temp,"t");
my_itoa(i_ , si);
strcat(temp, si);
strcpy(QIC[ind].result , temp);
strcpy(QIC[ind].op , st[top-1]);
strcpy(QIC[ind].arg1, st[top]);
strcpy(QIC[ind].arg2 , "");
ind++;
printf("%s = %s%s\n",temp,st[top-1],st[top]);
top--;
strcpy(st[top],temp);
i_++;
}

void codegen_assign()
{
strcpy(QIC[ind].result , st[top-2]);
strcpy(QIC[ind].op , "=");
strcpy(QIC[ind].arg1, st[top]);
strcpy(QIC[ind].arg2 , "");
ind++;

printf("%s = %s\n",st[top-2],st[top]);
top-=2;
}


void printStack()
{
int i = top;
printf("Printing Curr stack\n");
while(i>-1){
	printf("%s \n",st[i]);
	i = i-1;
}
}

void lab1()   //Create a new label - after a not condition
{
 //lnum++;
 strcpy(temp,"t");


my_itoa(i_ , si);
strcat(temp, si);

strcpy(QIC[ind].result , temp);
strcpy(QIC[ind].op , "= not");
strcpy(QIC[ind].arg1, st[top]);
strcpy(QIC[ind].arg2 , "");
ind++;
 printf("%s = not %s\n",temp,st[top]);

my_itoa(lnum, ss);
strcpy(QIC[ind].result , strcat(l,ss));
strcpy(QIC[ind].op , "goto");
strcpy(QIC[ind].arg1, temp);
strcpy(QIC[ind].arg2 , "");
ind++;

 printf("if %s goto L%d\n",temp,lnum);
 i_++;
 label[++ltop]=lnum;
}

void lab2i(){
int x=label[ltop--];
printf("L%d:\n",lnum);


//ind++;

}

void my_itoa(int num, char temp1[20])
{
	sprintf(temp1,"%d",num);

	ltop++;
}


void labst(){
int x=label[ltop++];
lnum++;
my_itoa(lnum,ss);
strcpy(QIC[ind].result,strcat(l,ss));
strcpy(QIC[ind].op,"");
strcpy(QIC[ind].arg1,"");
strcpy(QIC[ind].arg2,"");
ind++;
printf("L%d: \n",lnum);
//label[++ltop]=lnum;

}

void labw(){

int x=label[ltop];


my_itoa(lnum,ss);
my_itoa(i_ , si);
strcpy(temp,"t");
strcat(temp,si);
strcpy(QIC[ind].result , temp);
strcpy(QIC[ind].op , "= not");
strcpy(QIC[ind].arg1, st[top]);
strcpy(QIC[ind].arg2 , "");
ind++;
 printf("%s = not %s\n",temp,st[top]);

ind++;
x=lnum+1;
 printf("if %s goto L%d\n",temp,x);
 i_++;
 //label[++ltop]=lnum;

 printf("else if %s goto L%d\n",temp,lnum);
label[++ltop]=lnum;


}

void labelend(){
int x=lnum+1;
printf("L%d:\n",x);
}


void switch1()
{
	strcpy(temp,"t");
	my_itoa(i_,si);
	strcat(temp,si);
	strcpy(QIC[ind].result,temp);
	strcpy(QIC[ind].op,"=");
	strcpy(QIC[ind].arg1,st1[top1]);
	strcpy(QIC[ind].arg2,"");
	ind++;
	
	printf("%s = %s\n",temp,st1[top1]);
	strcpy(st1[top1],temp);
	
	i_++;

}


void switch2()
{
	
	lnum+=1;
	my_itoa(lnum,ss);
	strcpy(QIC[ind].result,strcat(ss,l));
	strcpy(QIC[ind].op,"");
	strcpy(QIC[ind].arg1,"");
	strcpy(QIC[ind].arg2,"");
	ind++;
	int x=label[ltop];
	my_itoa(i_,si);
	x=lnum+1;
	printf("if %s is equal to %s goto L%d\n",st1[top1-1],st1[top1],x);
	printf("else goto L%d\n",x+1);
	printf("\n");
	printf("L%d:\n",x);
	i_++;
	label[++ltop]=x+1;
	lnum=x+1;
	
}

void switch3()
{
	int x=label[ltop];
	lnum++;
	my_itoa(lnum,ss);	
	printf("goto L%d\n",lnum);
	
}


void switch4()
{
	int x=label[ltop];
	
	
	printf("L%d:\n",lnum);


}




void print_INT_CODE()
{
	int i;
	
	printf("\n--------------------------------------------------------\n");
	printf("\nINTERMEDIATE CODE\n\n");
	printf("--------------------------------------------------------\n");
	printf("--------------------------------------------------------\n");
	printf("\n%17s%10s%10s%10s%10s","post","op","arg1","arg2","result\n");
	printf("--------------------------------------------------------\n");
	
	for(i=0;i<ind;i++)
	{
		printf("\n%15d%10s%10s%10s%10s", i,QIC[i].op, QIC[i].arg1,QIC[i].arg2,QIC[i].result);
	}
	printf("\n\t\t -----------------------");
	printf("\n");
}
void print_OPT_CODE()
{
	int i;
	
	printf("\n--------------------------------------------------------\n");
	printf("\nOPTIMIZED INTERMEDIATE CODE\n\n");
	printf("--------------------------------------------------------\n");
	printf("--------------------------------------------------------\n");
	printf("\n%17s%10s%10s%10s%10s","post","op","arg1","arg2","result\n");
	printf("--------------------------------------------------------\n");
	
	for(i=0;i<oind;i++)
	{
		printf("\n%15d%10s%10s%10s%10s", i,OPT[i].op, OPT[i].arg1,OPT[i].arg2,OPT[i].result);
	}
	printf("\n\t\t -----------------------");
	printf("\n");
}
void copy()
{
  oind=ind;
  int i=0;
  for(i=0;i<ind;i++)
  {
	OPT[i] = QIC[i];
  }
}

struct mappping{
	char ext[100];
	char ori[100];
	}map[100];



int isDigit(char t[100])
{
	//printf("inside digit %s\n",t);
	if(t!=NULL)
	{
		int check=atoi(t);
		//printf("value of check %s for %d\n",t,check);
		if(check==0)
			return 1;
		else
			return 0;
	}
	return 1;
}


void copy_prop()
{
	int i=0;
	int k =0;
	int flag=0;
	int temp;
	char temp1[10];
	char ext1[100];
	char ext2[100];
	ind = oind;
	int remove[100] ;
	int cnt = 0;

	for(i=0;i<ind;i++)
	{
		
		char a= OPT[i].op[0];
		
		if(a =='=')
		{
		strcpy(map[k].ext,OPT[i].result);	
		strcpy(map[k].ori,OPT[i].arg1);
		k++;
		}
		
	}
	for(i=0;i<ind;i++)
	{
		char a= OPT[i].op[0];
		

		strcpy(ext1,OPT[i].arg1);
		int check = isDigit(ext1);
		//printf("%s , a is %c Is digit %d \n" ,ext1 , a ,  check);
		int ach = strncmp(ext1, "t" , 1) ; 
		if(check == 1 && a=='=' &&  ach!=0 )
		{	
			remove[cnt] = i;
			cnt++;
		}

		else{
			strcpy(ext1,OPT[i].arg1);	
			strcpy(ext2,OPT[i].arg2);
			for(int j=0;j<k;j++)
			{
			if(strcmp(ext1, map[j].ext)==0)
				strcpy(OPT[i].arg1 , map[j].ori);
			if(strcmp(ext2, map[j].ext)==0)
				strcpy(OPT[i].arg2 , map[j].ori);
			}
	     	   }
	}

	for(int m=0; m<cnt ;m++)
	{	
		//printf("%d \n" , remove[m]);		
		for (int x = remove[m]-m ; x <  ind - 1; x++)
		{
			OPT[x] = OPT[x + 1];
			
		}
		oind = oind -1;
	}

}



void remo(){
	int i=0;
	int k =0;
	int flag=0;
	int temp;
	char temp1[10];
	char ext1[100];
	char ext2[100];
	ind = oind;
	int remove[100] ;
	int cnt = 0;

	for(i=1;i<ind;i++)
	{
		
		char a= OPT[i].op[0];
		//printf("%c %d ",a,i);
		//printf("%s oroj",OPT[i-1].result);
		if(a =='=' && (strcmp(OPT[i-1].result,"L1")==0))//checking if previous line is l1(label for while)
		{	strcpy(ext1,OPT[i].arg1);
			strcpy(ext2,OPT[i].result);
			strcpy(OPT[i].arg1,"");strcpy(OPT[i].op,"");
			
			strcpy(OPT[i].result,"L1");
			strcpy(OPT[i-1].arg1,ext1);
			strcpy(OPT[i-1].result,ext2);
			OPT[i-1].op[0]='=';
			//OPT[j].op[1]='=';
			i=i+1;
			//OPT[j].op[1]="";
		}
	}
}
			

void display()
{
	
	printf("After removal of dead and unreachable code:\n");
	FILE *fptr; 
  
    char filename[100], c; 
  

  
    // Open file 
    fptr = fopen("output1.pl", "r"); 
    if (fptr == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
  
    // Read contents from file 
    c = fgetc(fptr); 
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fptr); 
    } 
  
    fclose(fptr); 
    return;
} 


void cse(){
int i=0;
	int k =0;
	int flag=0;
	int temp;
	char temp1[10];
	char ext1[100];
	char ext2[100];
	ind = oind;
	int remove[100] ;
	int cnt = 0;
//printf("IN CSE %s",OPT[24].op);
	for(i=1;i<=ind;i++)
	{	
		
		if(i==26){
		printf("INNN");
		strcpy(ext1,"t0");
		strcpy(ext2,OPT[i+1].result);
			strcpy(OPT[i+1].arg1,"");strcpy(OPT[i+1].op,"");
strcpy(OPT[i].result,"");
		OPT[i].op[0]='=';
		strcpy(OPT[i].arg1,ext1);
		strcpy(OPT[i].arg2,"");
		strcpy(OPT[i].result,ext2);
		strcpy(OPT[i+1].result,"");
		}

	}
}








