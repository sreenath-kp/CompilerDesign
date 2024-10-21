%{
	int words = 0, chars = 0, lines = 0, spaces = 0;
%}
%%
[^\t\n ]+ { words++;
	chars = chars + yyleng; }
[ ] { spaces++;
	chars++; }
[\n] {	lines++;
	chars++; }
%%
int yywrap(){}
void main(){
	yyin = fopen("input.txt", "r");
	yylex();
	fclose(yyin);
	printf("words : %d\ncharacters : %d\nlines : %d\nspaces : %d\n", words, chars, lines, spaces);
}