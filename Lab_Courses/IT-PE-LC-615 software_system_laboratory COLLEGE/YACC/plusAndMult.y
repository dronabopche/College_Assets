%{
#include <stdio.h>
#include <stdlib.h>
%}

%token NUMBER
%left '+'
%left '*'

%%
E : E '+' E   { printf("Add\n"); }
  | E '*' E   { printf("Multiply\n"); }
  | NUMBER
  ;
%%

int main() {
    printf("Enter expression:\n");
    yyparse();
    return 0;
}

int yyerror() {
    printf("Invalid Expression\n");
    return 0;
}