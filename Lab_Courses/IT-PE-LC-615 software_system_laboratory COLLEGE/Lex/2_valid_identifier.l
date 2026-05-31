%{
#include<stdio.h>
%}
%%
[a-zA-Z_][a-zA-Z0-9_]* { printf("Valid Identifier: %s\n", yytext); }
.                        { printf("Invalid\n"); }
%%
int main(){ yylex(); return 0; }
int yywrap(){ return 1; }
