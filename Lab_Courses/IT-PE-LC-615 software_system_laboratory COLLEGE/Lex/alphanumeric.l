%{
#include <stdio.h>
%}

%%

[a-zA-Z][a-zA-Z0-9]*    { printf("valid string\n"); }

%%

int main()
{
    yylex();
    return 0;
}

int yyerror()
{
    return 0;
}

int yywrap()
{
    return 0;
}