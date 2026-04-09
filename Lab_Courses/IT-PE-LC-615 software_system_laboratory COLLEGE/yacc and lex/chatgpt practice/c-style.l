%{
#include <stdio.h>
%}

%%
[a-zA-z][a-zA-Z0-9_]* { printf("valid\n");}

%%
int main(){
	yylex();
	return 0;
}

int yyerror(){
	return 0;
}

int yywrap(){
	return 0;
}