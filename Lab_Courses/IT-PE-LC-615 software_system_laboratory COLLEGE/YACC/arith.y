/* arith.y – Parser for Arithmetic Expression (+ - * only) */
%{
#include<stdio.h>
%}
%token NUM
%%
expr : expr '+' expr  { printf("%d\n", $1 + $3); }
     | expr '-' expr  { printf("%d\n", $1 - $3); }
     | expr '*' expr  { printf("%d\n", $1 * $3); }
     | NUM            { $$ = $1; }
     ;
%%
int main(){ yyparse(); return 0; }
int yyerror(char *s){ printf("Error: %s\n", s); return 0; }
