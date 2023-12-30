%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdarg.h>
#include "lex.yy.c"
void yyerror(const char*);
int yylex();
void print_sym_tab();
void update_sym_tab(char* typ, char* nam, int line, int scope);
int scope[100];
int scope_ctr;
int scope_ind;
char typ[10]="none";

typedef struct AST{
	char lexeme[100];
	int NumChild;
	struct AST **child;
}AST_node;

struct AST* make_if_node(char* root, AST_node* child1, AST_node* child2, AST_node* child3);
struct AST* make_switch_node(char* root, AST_node* child1, AST_node* child2, AST_node* child3,AST_node* child4);
struct AST * make_node(char*, AST_node*, AST_node*);
struct AST* make_leaf(char* root);
void AST_print(struct AST *t);
extern FILE* yyin;
extern int yylineno;
%}

%locations
%token T_If T_Print T_Do T_While T_Switch T_Else T_Case  T_Assignop T_Pluseq T_Shebang T_Minuseq T_Exp T_String T_True T_False T_Use T_Arr
T_Id T_Int T_Float T_Double T_Inc T_Dec T_Lesseq T_Greteq T_Or T_And T_Not T_Eq T_Noteq
%left '>' '<' '=' T_Pluseq T_Minuseq
%left '+' '-' '*' '/' '%' ","
%left T_Inc T_Dec

%union {
	char var_type[100]; 
	char text[100]; 
	struct AST *node;
	}
%start P

%% 

P : T_Shebang S {printf("in yacc\n");$<node>1=make_leaf("Shebang_line");$<node>$=make_node("Shebang",$<node>1,$<node>2);printf("\n\nAbstract Syntax Tree:\n\n");AST_print($<node>$);YYACCEPT;}
  ;

S: Declaration';'S {$<node>$=make_node("Declr",$<node>1,$<node>3);}
 | T_Do '{'S'}' T_While'('cond')' ';' S {$<node>$=make_if_node("Do while",$<node>3,$<node>7,$<node>10);}
 | us  S  T_Switch '('arg')''{' st '}' S {$<node>$=make_switch_node("use_Switch",$<node>2,$<node>5,$<node>8,$<node>10);}
 | T_Print T_String ';' S 
 | T_Print '(' T_String ')' ';' S
 | T_Print '('T_Id')' ';' S
 | T_If '(' cond ')' '{'S'}' S {$<node>$=make_if_node("If",$<node>3,$<node>6,$<node>8);}
 | ue';'S 
 | ArrayDecl ';' S
 | error S { yyerrok;yyclearin;  }
 |         {$<node>$=make_leaf("epsilon");}
 ;

num:T_Int    {strcpy($<var_type>$,$<var_type>1);strcpy(typ,$<var_type>1);}
   |T_Float  {strcpy($<var_type>$,$<var_type>1);strcpy(typ,$<var_type>1);} 
   |T_Double {strcpy($<var_type>$,$<var_type>1);strcpy(typ,$<var_type>1);} 
   ;
ArrayDecl: T_Arr'=' '(' ')' 
         | T_Arr'=''('Di')'  
         ;
Di:num','Di
 |T_String','Di
 |num
 |T_String
 ;

Declaration:L {$<node>$=$<node>1;}
	   ;

L:L ',' X {$<node>$=make_node("varlist",$<node>1,$<node>3);}
 |X {$<node>$=$<node>1;}
 ;

X:T_Id  {$<node>$=make_leaf($<text>1);}
 |Assign_expr {printf("ae\n");$<node>$=$<node>1;}
 ;
str:T_String {$<node>$=make_leaf($<text>1);}
   ;

Assign_expr:T_Id'='E {$<node>1=make_leaf($<text>1); $<node>$=make_node("=",$<node>1,$<node>3);}
	   |T_Id'='T_String {$<node>1=make_leaf($<text>1);$<node>3=make_leaf(yylval.text);$<node>$=make_node("=",$<node>1,$<node>3);}
	   |T_Id'='B {$<node>$=make_node("=",$<node>1,$<node>3);}
	   ;

B:T_Id'.'T_Id {$<node>$=make_node("concat",$<node>1,$<node>3);}
  | error '\n' { yyerrok;                  }
  ; 
cond:cond T_Or C {$<node>$=make_node("or",$<node>1,$<node>3);}
    |C {$<node>$=$<node>1;}
    ;

C: C T_And D {$<node>$=make_node("and",$<node>1,$<node>3);}
 |D {$<node>$=$<node>1;}
 ;

D:T_Not 
 |M {$<node>$=$<node>1;}
 ;

M:'('cond')' {$<node>$=$<node>2;}
 |relexp     {$<node>$=$<node>1;}
 |T_True
 |T_False
 ;

relexp: relexp '<' E {$<node>$=make_node("<",$<node>1,$<node>3);}
      | relexp '>' E {$<node>$=make_node(">",$<node>1,$<node>3);}
      | relexp "<=" E {$<node>$=make_node("<=",$<node>1,$<node>3);}
      | relexp ">=" E {$<node>$=make_node(">=",$<node>1,$<node>3);}
      | relexp "!=" E {$<node>$=make_node("!=",$<node>1,$<node>3);}
      | relexp "==" E {$<node>$=make_node("==",$<node>1,$<node>3);}
      |T_Id {$<node>$=make_leaf($<text>1);}
      |num  {$<node>$=make_leaf($<text>1);}
      |str  {$<node>$=make_leaf($<text>1);}
      ;


E:E'+'T   {$<node>$=make_node("+",$<node>1,$<node>3);}
  |E'-'T  {$<node>$=make_node($<text>2,$<node>1,$<node>3);}	
  |T      {$<node>$=$<node>1; }
  |ue     {$<node>$=$<node>1;}
  ;
T:T'*'F	 {$<node>$=make_node($<text>2,$<node>1,$<node>3);}	
 |T'/'F	 {$<node>$=make_node($<text>2,$<node>1,$<node>3);}	
 |F      {$<node>$=$<node>1;}
 ;
F:N T_Exp F {$<node>$=make_node($<text>2,$<node>1,$<node>3);}
 |N {$<node>$=$<node>1;}
 ;
N:T_Id  {$<node>$=make_leaf($<text>1); fprintf(yyout,"in tid%s\n",$<text>1);} 
 |num  {$<node>$=make_leaf($<text>1);}
 |'('E')' {$<node>$=$<node>2;}
 ;

ue:T_Id T_Inc {$<node>1=make_leaf($<text>1);$<node>2=make_leaf("+");$<node>$=make_node("+",$<node>1,$<node>2);}
  |T_Id T_Dec {$<node>1=make_leaf($<text>1);$<node>2=make_leaf("-");$<node>$=make_node("-",$<node>1,$<node>2);}
  |T_Inc T_Id {$<node>2=make_leaf($<text>2);$<node>1=make_leaf("+");$<node>$=make_node("+",$<node>1,$<node>2);}
  |T_Dec T_Id {$<node>2=make_leaf($<text>2);$<node>1=make_leaf("-");$<node>$=make_node("-",$<node>1,$<node>2);}
  ;
us:T_Use T_Switch ';'
  ;
arg:T_Id {$<node>$=make_leaf($<text>1);}
   |num {$<node>$=make_leaf($<text>1);}
   ;
st:T_Case Y O {$<node>$=make_node("case",$<node>2,$<node>3);}
  ;
Y:K '{'S'}' {$<node>$=make_node("case_arg",$<node>1,$<node>3);}
 ;
K:num {$<node>$=make_leaf($<text>1);}
 |T_Id {$<node>$=make_leaf($<text>1);}
 |T_String  {$<node>$=make_leaf($<text>1);}
 ;
O:T_Else '{'S'}' {$<node>2=make_leaf("NULL");$<node>$=make_node("default",$<node>3,$<node>2);}
 |st	{$<node>$=$<node>1;}
 ;




		  ;
%%
void yyerror(const char* arg)
{
	printf("%s\n",arg);
}

struct entry
{
	char name[30];
	char type[10];
	int width;
	int line_num;
	int scope;
};




struct entry sym_tab[100];
int ctr = 0;

void update_sym_tab(char* typ, char* nam, int line, int scope)
{
	strcpy(sym_tab[ctr].name,nam);

	if(strcmp(typ,"int")==0)
	{
		strcpy(sym_tab[ctr].type,typ);
		sym_tab[ctr].width=4;
	}

	else if(strcmp(typ,"float")==0)
	{
		strcpy(sym_tab[ctr].type,typ);
		sym_tab[ctr].width=8;
	}
	else if(strcmp(typ,"char")==0)
	{
		strcpy(sym_tab[ctr].type,typ);
		sym_tab[ctr].width=1;	
	}
	sym_tab[ctr].line_num=line;
	sym_tab[ctr].scope=scope;
	ctr++;


}


void print_sym_tab()
 { 	
 		int i; 	
		printf("\n\nSymbol Table: \n"); 
		for(i=0;i<ctr;i++) 	
		{ 		
			printf("Token: %s, Type: %s, Size: %d, Line Number: %d, Scope: %d\n \n",sym_tab[i].name, sym_tab[i].type, sym_tab[i].width,sym_tab[i].line_num,sym_tab[i].scope); 	} 

}

int look_up_sym_tab(char* nam)
{
	int i; 
	for(i=0;i<ctr;i++)
	{
		if(strcmp(sym_tab[i].name,nam)==0)
		{
			int scop=sym_tab[i].scope;
			int flag=0;
			int zero_ctr=0;
			int j=scope_ind-1;
			while(j>=0)
			{
				if(scope[j]==0)
					zero_ctr++;
				else if(scope[j]!=0 && zero_ctr>0)
					zero_ctr--;
				else if(scope[j]!=0 && zero_ctr==0)
				{
					if(scope[j]==scop)
					{
						flag=1;
						return 1;
					}
				}
				j--;
			}
		}
	}
	return 0;
}

int look_up_sym_tab_dec(char* nam, int scop)
{
	int i; 
	for(i=0;i<ctr;i++)
	{
		if(strcmp(sym_tab[i].name,nam)==0 && sym_tab[i].scope==scop)
		{
			return 1;
		}
	}
	return 0;
}


void AST_print(struct AST *t)
{
	static int ctr=0;
	//printf("inside print tree\n");
	int i;
	if(t->NumChild==0) 
		return;

	struct AST *t2=t;
	printf("\nRoot:%s\n",t2->lexeme);
	printf("Children: ");

	for(i=0;i<t2->NumChild;++i) 
	{
		printf("%s ",t2->child[i]->lexeme);
	}
	printf("\n\n");	
	for(i=0;i<t2->NumChild;++i)
	{
		AST_print(t->child[i]);
	}


	
}




/*void AST_print(struct AST *t)
{
	static int ctr=0;
	//printf("inside print tree\n");
	int i;
	if(t->NumChild==0) 
		return;
	struct AST *t2=t;
	printf("\n[ %s ",t2->lexeme);
	
	for(i=0;i<t2->NumChild;++i) 
	{
		printf("%s ",t2->child[i]->lexeme);
	}
	printf("]");	
	for(i=0;i<t2->NumChild;++i)
	{
		AST_print(t->child[i]);
	}
	
}*/







struct AST* make_node(char* root, AST_node* child1, AST_node* child2)
{
	//printf("Creating new node\n");
	struct AST * node = (struct AST*)malloc(sizeof(struct AST));
	node->child = (struct AST**)malloc(2*sizeof(struct AST *));
	node->NumChild = 2;//
	strcpy(node->lexeme,root);
	//printf("Copied lexeme\n");
	//printf("%s\n",node->lexeme);
	node->child[0] = child1;
	node->child[1] = child2;
	return node;
}

struct AST* make_if_node(char* root, AST_node* child1, AST_node* child2, AST_node* child3)
{
	//printf("Creating new node\n");
	struct AST * node = (struct AST*)malloc(sizeof(struct AST));
	node->child = (struct AST**)malloc(3*sizeof(struct AST *));
	node->NumChild = 3;
	strcpy(node->lexeme,root);
	node->child[0] = child1;
	node->child[1] = child2;
	node->child[2] = child3;

	return node;
}
struct AST* make_switch_node(char* root, AST_node* child1, AST_node* child2, AST_node* child3,AST_node*child4)
{
	//printf("Creating new node\n");
	struct AST * node = (struct AST*)malloc(sizeof(struct AST));
	node->child = (struct AST**)malloc(4*sizeof(struct AST *));
	node->NumChild = 4;
	strcpy(node->lexeme,root);
	node->child[0] = child1;
	node->child[1] = child2;
	node->child[2] = child3;
	node->child[3] = child4;
	return node;
}


struct AST* make_leaf(char* root)
{
	//printf("Creating new leaf ");
	struct AST * node = (struct AST*)malloc(sizeof(struct AST));
	strcpy(node->lexeme,root);
	//printf("%s\n",node->lexeme);
	node->NumChild = 0;
	node->child = NULL;
	return node;
}



int main(int argc,char* *argv)
{
	printf("Parsing the following Input:\n\n");
	//yyin=fopen("Input.txt","r");
	//print_sym_tab();
	//yylex();
	char ch,c;
	FILE *f;    
	if(argc != 2) {printf("useage:  calc filename \n"); exit(1);}
	if( !(yyin = fopen(argv[1],"r")) ){ 
	       printf("cannot open file\n");exit(1);
 }
	
	yyparse();
	printf("\n");
	return 0;
}

int get_scope()
{
	//printf("ind :%d\n",scope_ind);
	int i=scope_ind-1;
	int zero_ctr=0;
	int flag=1;
	while(flag && i>0)
	{
		if(scope[i]!=0)
			zero_ctr--;
		else
			zero_ctr++;
		if(zero_ctr==0)
		{
			i--;
			flag=0;
			break;
		}
		i--;
	}
	return scope[i];
}

