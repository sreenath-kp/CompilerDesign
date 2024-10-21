%token LETTER DIGIT NL;
%%
start: variable NL { printf("Valid\n"); exit(0);}
variable: LETTER alnum;
alnum: LETTER alnum | DIGIT alnum | LETTER | DIGIT ;
%%
int yyerror(){
	printf("INvalid\n");
	exit(1);
}
int main()
{
	printf("Enter id : ");
	yyparse();
}