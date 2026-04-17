%{
#include <stdio.h>
%}

%%
"+"     { printf("Addition Operator\n"); }
"-"     { printf("Subtraction Operator\n"); }
"*"     { printf("Multiplication Operator\n"); }
"/"     { printf("Division Operator\n"); }
"%"     { printf("Modulus Operator\n"); }
"="     { printf("Assignment Operator\n"); }
"=="    { printf("Equality Operator\n"); }
"!="    { printf("Not Equal Operator\n"); }
">"     { printf("Greater Than Operator\n"); }
"<"     { printf("Less Than Operator\n"); }
">="    { printf("Greater Than or Equal Operator\n"); }
"<="    { printf("Less Than or Equal Operator\n"); }

[ \t\n]    ;   /* Ignore whitespace */

.       { printf("Invalid Operator\n"); }
%%

int main() {
    printf("Enter an operator:\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}