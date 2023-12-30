%{
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
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
if		{print(yytext);printf("T_If\n"); return T_If;}
use		{print(yytext);printf("T_Use\n"); return T_Use;}
print	        {print(yytext);printf("T_Print\n"); return T_Print;}
do		{print(yytext);printf("T_Do\n"); return T_Do;}
while		{print(yytext);printf("T_While\n"); return T_While;}
[Ss]witch		{print(yytext);printf("T_switch\n"); return T_Switch;}


else		{print(yytext);printf("T_Else\n"); return T_Else;}
case		{print(yytext);printf("T_Case\n"); return T_Case;}
true		{print(yytext);return T_True;}
false		{print(yytext);return T_False;}


"#!/usr/bin/perl" {printf("T_Shebang\n"); return T_Shebang;}
[^shebang]{single_line_comment}.* {;}
($)({letter}|_)({letter}|_|{digit})* {strcpy(yylval.text,yytext);fprintf(yyout ,"%s in lex\n",yylval.text);return T_Id;}
 
(@)({letter}|_)({letter}|_|{digit})* {if(strlen(yytext)>31){int x=strlen(yytext)-31;yytext[strlen(yytext)-x]='\0';return T_Id;} else{print(yytext);return T_Arr;}}

{digit}+	{strcpy(yylval.var_type,yytext);return T_Int;}

({digit}+"."{digit}*)|({digit}*"."{digit}+) {strcpy(yylval.var_type,yytext);return T_Float;}

{digit}*(\.{digit})?(("E"|"e")("+"|"-")?{digit})? {strcpy(yylval.var_type,yytext);print(yytext); return T_Double;}

\"[^"\n]*\" 	                                    { strcpy(yylval.text,yytext);printf("%s",yylval.text);print(yytext);return T_String;}
[-+/%=\(\)\[\]\{\};\,\.\<\>]                          { print(yytext);return *yytext;}
[\'\"]			{print(yytext);return *yytext;}

"!"		{strcpy(yylval.text,yytext);print(yytext); return T_Not;}
"||"		{strcpy(yylval.text,yytext);print(yytext); return T_Or;}
"&&"		{strcpy(yylval.text,yytext);print(yytext); return T_And;}

"++"		{strcpy(yylval.text,yytext);print(yytext); return T_Inc;}
"--"		{strcpy(yylval.text,yytext);print(yytext); return T_Dec;}
"=="		{strcpy(yylval.text,yytext);print(yytext); return T_Eq;}
"+="		{strcpy(yylval.text,yytext);print(yytext); return T_Pluseq;}
"-="		{strcpy(yylval.text,yytext);print(yytext); return T_Minuseq;}
"**"		{strcpy(yylval.text,yytext);print(yytext);	return T_Exp;}
"!="		{strcpy(yylval.text,yytext);print(yytext); return T_Noteq;}
"<="		{strcpy(yylval.text,yytext);print(yytext); return T_Lesseq;}
">="		{strcpy(yylval.text,yytext);print(yytext); return T_Greteq;}
%%

int yywrap(void){
return 1;
}



