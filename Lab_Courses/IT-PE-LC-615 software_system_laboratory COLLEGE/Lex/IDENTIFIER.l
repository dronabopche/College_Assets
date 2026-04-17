%{
#include <stdio.h>
%}
%%
^[a-zA-Z][a-zA-Z0-9]*$   { printf("Valid Identifier\n"); }
.*                       { printf("Invalid Identifier\n"); }
%%
int main() {
    yylex();
    return 0;
}
int yywrap() {
    return 1;
}