%{
	#include <stdio.h>
%}
%%
"abc" { printf("ABC"); }
. { printf("%s", yytext); }
%%
int yywrap(){}
int main(){
	yywrap();
	printf("Enter str : ");
	yylex();
	return 0;
}
