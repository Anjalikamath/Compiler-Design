# Compiler-Design

Project Title: Building a mini compiler based on Perl Language


Project Guide : Prof. Preet Kanwal

Project Abstract: The aim of the project is to build a mini compiler based on perl language. It is done by diving the project into phases.
1. Context free grammar generation
2. Lexical Analysis
3. Abstract Syntax Tree and Intermediate Code Generation
4. Code Optimization
5. Assembly Code Generation

Code Execution : 

For all phases except last phase i.e assembly phase execution is as follows: <br>
 lex lexer.l <br>
 yacc -d parser.y  <br>
 gcc y.tab.c  <br>
 ./a.out input.pl  <br>

 For the Phase5-assembly execution is as follows:  <br>
 python3 assembly.py
 
