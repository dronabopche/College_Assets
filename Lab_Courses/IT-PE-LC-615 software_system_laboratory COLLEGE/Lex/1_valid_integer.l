%{
#include<stdio.h>
%}
%%
[0-9]+ { printf("Valid Integer: %s\n", yytext); }
.      { printf("Invalid\n"); }
%%
int main(){ yylex(); return 0; }
int yywrap(){ return 1; }
