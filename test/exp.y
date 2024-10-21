%{
    #include <stdio.h>
%}
%token id op NL;
%left op
%%
    S : expr NL { printf("Valid expr\n") ; }
    ;
    expr : expr op expr 
    | id
    ;

%%
int yyerror()
{
    printf("Invalid expr\n") ;
}
int main()
{
	printf("\nEnter the expression: \n");
	yyparse();
}