%{
    int valid = 0;
%}
%%
[7-9][0-9]{9} { printf("Valid\n%s\n",yytext);return 0;}
. { printf("Invalid");return 0;}
%%
int yywrap(){}
int main()
{   
    printf("Enter phone number:");
    yylex();
}