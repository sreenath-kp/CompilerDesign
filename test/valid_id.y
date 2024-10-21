%{
    #include <stdio.h>
%}
%token letter digits;
%%
    S : letter A { printf("Valid id\n") ; }
    ;
    A : letter
    | digits
    ;
%%
int yyerror()
{
    printf("Invalid id");
}
int main()
{
    printf("Enter id : ");
    yyparse();

}