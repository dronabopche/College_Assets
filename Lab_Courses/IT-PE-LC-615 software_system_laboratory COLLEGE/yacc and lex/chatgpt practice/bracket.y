%{
#include<stdio.h>
#include<ctype.h>
int yylval;
%}
%token id
%left "+" "-"
%left "*" "/"
%%
S: E '\n' { printf("%d", $1); }
;

E: E '+' E { $$ = $1 + $3; }
 | E '*' E { $$ = $1 * $3; }
 | E '-' E { $$ = $1 - $3; }
 | E '/' E { $$ = $1 / $3; }
 | '(' E ')' {$$ = $2; }
 | id {$$ = $1;}
;
%%
int main(){
	yyparse();
	return 0;
}
int yylex(){
	int a;
	a = getchar();
	if (isdigit(a))
   	 {
        	yylval = a - '0'; 
        	return id;
    	}
    	return a;
}

int yyerror()
{
    return 0;
}

int yywrap()
{
    return 0;
}