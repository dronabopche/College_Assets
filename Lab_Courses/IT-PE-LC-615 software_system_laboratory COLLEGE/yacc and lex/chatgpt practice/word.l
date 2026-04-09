%{
#include <stdio.h>
%}

%%
if { printf("keyword\n");}
main { printf("identifier\n");}
return { printf("keyword\n");}
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