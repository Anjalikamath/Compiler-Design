%{
#include<stdlib.h>
#include<stdio.h>
#include "y.tab.h"

int yylex();



//#define error 0
int error=0;

void print(char* s)
{
	if(error)
	{
		printf("Error : %d:%s\n",yylineno,s);
	}
return;
}

%}

%option yylineno
digit [0-9]
letter [a-zA-z]
alphanum ({number}|{letter})
single_line_comment #
multi_open  =begin
multi_close =cut
shebang #!/usr/bin/perl 
%%
\n|" "|\t	{}   //skip over whitespace

{multi_open}(.*[\n]*{multi_close}*[\n]*.*)*{multi_close} {}
if		{print(yytext); yylval=malloc(100*sizeof(char)); strcpy(yylval,yytext);printf("T_If\n"); return T_If;}
use		{print(yytext); yylval=malloc(100*sizeof(char)); strcpy(yylval,yytext);printf("T_Use\n"); return T_Use;}
print	        {print(yytext); yylval=malloc(100*sizeof(char)); strcpy(yylval,yytext); printf("T_Print\n"); return T_Print;}
do		{print(yytext); yylval=malloc(100*sizeof(char)); strcpy(yylval,yytext);  printf("T_Do\n"); return T_Do;}
while		{print(yytext); yylval=malloc(100*sizeof(char)); strcpy(yylval,yytext); printf("T_While\n"); return T_While;}
[Ss]witch		{print(yytext); yylval=malloc(100*sizeof(char)); strcpy(yylval,yytext); printf("T_switch\n"); return T_Switch;}


else		{print(yytext); yylval=malloc(100*sizeof(char)); strcpy(yylval,yytext); printf("T_Else\n"); return T_Else;}
case		{print(yytext); yylval=malloc(100*sizeof(char)); strcpy(yylval,yytext); printf("T_Case\n"); return T_Case;}
true		{print(yytext); yylval=malloc(100*sizeof(char)); strcpy(yylval,yytext); return T_True;}
false		{print(yytext); yylval=malloc(100*sizeof(char)); strcpy(yylval,yytext); return T_False;}


"#!/usr/bin/perl" {print(yytext);printf("T_Shebang\n"); return T_Shebang;}
[^shebang]{single_line_comment}.* {;}
($)({letter}|_)({letter}|_|{digit})* {if(strlen(yytext)>31){int x=strlen(yytext)-31;yytext[strlen(yytext)-x]='\0'; yylval = malloc(100*sizeof(char));  strcpy(yylval, yytext); return T_Id;}
 else{if(yytext[0]!='$'){error=1; print(yytext); } else{ print(yytext);  yylval = malloc(100*sizeof(char));  strcpy(yylval, yytext); return T_Id;}}}

(@)({letter}|_)({letter}|_|{digit})* {if(strlen(yytext)>31){int x=strlen(yytext)-31;yytext[strlen(yytext)-x]='\0'; yylval = malloc(100*sizeof(char));  strcpy(yylval, yytext); return T_Id;} else{print(yytext); yylval = malloc(100*sizeof(char));  strcpy(yylval, yytext); return T_Arr;}}

{digit}+	{print(yytext); return T_Int;}

({digit}+"."{digit}*)|({digit}*"."{digit}+) {print(yytext); return T_Float;}

{digit}*(\.{digit})?(("E"|"e")("+"|"-")?{digit})? {print(yytext); return T_Double;}

\"[^"\n]*\" 	                                    { print(yytext);return T_String;}
[-+/%=\(\)\[\]\{\};\,\.\<\>]                          { print(yytext);return *yytext;}
[\'\"]			{print(yytext);printf("%c",*yytext); return *yytext;}

"!"		{print(yytext); return T_Not;}
"||"		{print(yytext); return T_Or;}
"&&"		{print(yytext); return T_And;}

"++"		{print(yytext); return T_Inc;}
"--"		{print(yytext); return T_Dec;}
"=="		{print(yytext); return T_Eq;}
"+="		{print(yytext); return T_Pluseq;}
"-="		{print(yytext); return T_Minuseq;}
"**"		{print(yytext);	return T_Exp;}
"!="		{print(yytext); return T_Noteq;}
"<="		{print(yytext); return T_Lesseq;}
">="		{print(yytext); return T_Greteq;}
%%

int yywrap(void){
return 1;
}



