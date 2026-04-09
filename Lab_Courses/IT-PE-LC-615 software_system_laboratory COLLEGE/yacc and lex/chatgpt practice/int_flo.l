%{
#include <stdio.h>
%}

%%
[0-9]+         { printf("valid int\n"); } 
[0-9]+\.[0-9]+ { printf("valid float\n"); }
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