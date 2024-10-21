%{
	#include <stdio.h>
	int valid = 1;
%}
%token id num op;
%%
start: id '=' s|s;
s: id x | num x | '-' num x | '(' s ')' x;
x: op s | '-' s | ;  
%%
int yyerror(){
	valid = 0;
	printf("Invalid expression.\n");
}
int main(){
	printf("Enter str : ");
	yyparse();
	if (valid){
		printf("Valid expression !!");
	}
	return 0;
}