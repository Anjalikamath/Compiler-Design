/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_If = 258,
     T_Print = 259,
     T_Do = 260,
     T_While = 261,
     T_Switch = 262,
     T_Else = 263,
     T_Case = 264,
     T_Assignop = 265,
     T_Pluseq = 266,
     T_Shebang = 267,
     T_Minuseq = 268,
     T_Exp = 269,
     T_String = 270,
     T_True = 271,
     T_False = 272,
     T_Use = 273,
     T_Arr = 274,
     T_Id = 275,
     T_Int = 276,
     T_Float = 277,
     T_Double = 278,
     T_Inc = 279,
     T_Dec = 280,
     T_Lesseq = 281,
     T_Greteq = 282,
     T_Or = 283,
     T_And = 284,
     T_Not = 285,
     T_Eq = 286,
     T_Noteq = 287
   };
#endif
/* Tokens.  */
#define T_If 258
#define T_Print 259
#define T_Do 260
#define T_While 261
#define T_Switch 262
#define T_Else 263
#define T_Case 264
#define T_Assignop 265
#define T_Pluseq 266
#define T_Shebang 267
#define T_Minuseq 268
#define T_Exp 269
#define T_String 270
#define T_True 271
#define T_False 272
#define T_Use 273
#define T_Arr 274
#define T_Id 275
#define T_Int 276
#define T_Float 277
#define T_Double 278
#define T_Inc 279
#define T_Dec 280
#define T_Lesseq 281
#define T_Greteq 282
#define T_Or 283
#define T_And 284
#define T_Not 285
#define T_Eq 286
#define T_Noteq 287




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 38 "yacc.y"
{
	char var_type[100]; 
	char text[100]; 
	struct AST *node;
	}
/* Line 1529 of yacc.c.  */
#line 119 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;
