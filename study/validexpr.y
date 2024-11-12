%{
    #include "y.tab.h"
    #include <stdio.h>
%}
%token NUM ID NL 

%left '+' '-'
%left '/' '*'

%%
start : exp NL { printf("Valid Expression\n");}
exp : exp '+' exp
    | exp '-' exp
    | exp '/' exp
    | exp '*' exp
    | '(' exp ')'
    | NUM
    | ID
    ;
%%
int yyerror(){
    printf("Invalid expression\n");
    return 1;
}
int main(){
    printf("Enter Expression: ");
    yyparse();
    return 0;
}