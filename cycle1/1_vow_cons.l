%{
	int vowels = 0, consonants = 0;
%}
%%
[aeiouAEIOU] { vowels++ ; }
[a-zA-Z] { consonants++ ;}
%%
int yywrap(){}
void main(){
	// yyin = fopen("input.txt", "r");
	printf("Enter the string : ");
	yylex();
	// fclose(yyin);
	printf("No of vowels : %d\nNo of consonants : %d\n", vowels, consonants);
}