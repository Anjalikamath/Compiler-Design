Section : 6B

Project Title: Building a mini compiler based on Perl Language

Team Members: Divya Puranam(PES1201700749) , Sanjana Shekar(PES1201700905) , Anjali Kamath(PES1201701674)

Project Guide : Prof. Preet Kanwal

Project Abstract: The aim of the project is to build a mini compiler based on perl language. It is done by diving the project into phases.
1. Context free grammar generation
2. Lexical Analysis
3. Abstract Syntax Tree and Intermediate Code Generation
4. Code Optimization
5. Assembly Code Generation

Code Execution : 

For all phases except last phase i.e assembly phase execution is as follows:
 lex lexer.l
 yacc -d parser.y
 gcc y.tab.c
 ./a.out input.pl

 For the Phase5-assembly execution is as follows:
 python3 assembly.py
 
