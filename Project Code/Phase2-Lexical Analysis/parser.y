%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define YYSTYPE char*
#include "lex.yy.c"

void yyerror(const char *s);
#define M 1000

int yylex();
//void yyerror(char*);
extern int yylineno;


typedef struct Node{
    char name[100];
    char type[100];
    struct Node* next;
    int lno;

}node;

char type[M];


node* symbolTable[M]={NULL};

int hash(const char s[])
{
    int i;
    int p=0;
    for(i=0;i<strlen(s);i++)
    {
        p =(p*10 + s[i])%M;
    }
    return p;
}

node* lookup(const char s[])
{
   int h= hash(s);
   //printf("%s\n",s);
   //printf("%d\n",h);
   int len = strlen(s);

   node *temp = symbolTable[h];
   
   while(temp !=NULL){
        if(!strcmp(s, temp->name))
            return temp;
        else
            temp=temp->next; 
   }

   return NULL;

}

void insert(const char name[], const char type[], int l )
{
    if(lookup(name)!=NULL)
        return;
    int h = hash(name);
    node* temp = malloc(sizeof(node));
    
    strcpy(temp->name, name);
    strcpy(temp->type, type);
    temp->lno = l;

    temp->next = symbolTable[h];
    symbolTable[h]=temp;
    
}

void check(const char name[],const char type[],int l)
{
		
}

%}

%token T_If T_Print T_Do T_While T_Switch T_Else T_Case T_Id T_Int T_Float T_Double T_Eq T_Noteq T_Inc T_Dec T_Assignop T_Pluseq T_Shebang T_Minuseq T_Exp T_Lesseq T_Greteq T_Or T_And T_Not T_String T_True T_False T_Use T_Arr 

%left '>' '<' '=' T_Pluseq T_Minuseq
%left '+' '-' '*' '/' '%' ","
%left T_Inc T_Dec

%%
P : T_Shebang S
  ;

S: Declaration';'S
 | T_Do '{'S'}' T_While'('cond')' ';' S
 | us  S  T_Switch '('arg')''{' st '}' S
 | T_Print T_String ';' S
 | T_Print '(' T_String ')' ';' S
 | T_Print '('T_Id')' ';' S
 | T_If '(' cond ')' '{'S'}' S
 | ue';'S
 | ArrayDecl ';' S
 | error S { yyerrok;yyclearin;  }
 | 
 ;

num:T_Int    {insert($1,"int",yylineno);} 
   |T_Float  {insert($1,"float",yylineno);} 
   |T_Double {insert($1,"double",yylineno);} 
   ;
ArrayDecl: T_Arr'=' '(' ')' {insert($1,"array",yylineno);} 
         | T_Arr'=''('Di')' {insert($1,"array",yylineno);} 
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

X:T_Id  { insert($1,type,yylineno); }
 |Assign_expr
 ;
str:T_String {insert($1,"char",yylineno);}
   ;

Assign_expr:T_Id'='E { insert($1,"int",yylineno);} 
	   |T_Id'=' T_String {insert($1,"string",yylineno);}
	   |T_Id'='B {insert($1,"string",yylineno);}
	   ;

B:T_Id'.'T_Id
  | error '\n' { yyerrok;                  }
  ; 
cond:cond T_Or C
    |C
    ;

C: C T_And D
 |D
 ;

D:T_Not 
 |M
 ;

M:'('cond')'
 |relexp
 |T_True
 |T_False
 ;

relexp: relexp relop E
      |T_Id
      |num
      |str
      ;
relop: '<'
     |'>'
     |T_Lesseq
     |T_Greteq
     |T_Eq
     |T_Noteq
     ;

E:E'+'T   {insert($1,"int",yylineno); }
  |E'-'T	
  |T   
  |ue  
  ;
T:T'*'F		
 |T'/'F		
 |F
 ;
F:N T_Exp F
 |N
 ;
N:T_Id   
 |num  //{insert($1,"id",yylineno);}
 |'('E')'
 ;

ue:T_Id T_Inc
  |T_Id T_Dec
  |T_Inc T_Id
  |T_Dec T_Id
  ;
us:T_Use T_Switch ';'
  ;
arg:T_Id
   |num
   ;
st:T_Case Y O
  ;
Y:K '{'S'}'
 ;
K:num
 |T_Id
 |str
 ;
O:T_Else '{'S'}'
 |st
 ;

%%


void printSymbolTable()
{  
    node* temp=NULL;
    printf("---------------------------------------------------------------------\n");
    printf("%-10s|%-50s|%-30s\n", "LineNumber","Name","Type");
    printf("---------------------------------------------------------------------\n");
    for(int i=0;i<M;i++)
    {
        temp = symbolTable[i];

        while(temp!=NULL)
        {
            printf("%-10d|%-50s|%-30s\n",temp->lno, temp->name, temp->type );
            temp= temp->next;
        }
    }
}

int main(int argc, char* *argv)
{	
	//printf("Enter a string\n");
	char ch,c;
	FILE *f;    
	if(argc != 2) {printf("useage:  calc filename \n"); exit(1);}
	if( !(yyin = fopen(argv[1],"r")) ){ 
	       printf("cannot open file\n");exit(1);
 }
	  // yyout=fopen("out.pl","w");
	yyparse();
	//fclose(yyout);
	//printf("Valid\n"),exit(0);
	printSymbolTable();
    
       
	return 0;
}

void yyerror(const char *s) {
 printf("\nError occured at %d\n ",yylineno);
 //printf("%d ",yyerrorstate);
 fprintf(stderr, "%s\n\n", s);

} 




