%{
#include<stdio.h>
%}
%%
[0-9]+"."[0-9]+ { printf("Valid Float: %s\n", yytext); }
.               { printf("Invalid\n"); }
%%
int main(){ yylex(); return 0; }
int yywrap(){ return 1; }
