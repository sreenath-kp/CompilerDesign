%{
    #include <stdio.h>
    #include "y.tab.h"
    int na = 0, nb = 0;
%}
%token A B
%%
s   : A x {na++;}
    | B x {nb++;}
    ;
x   : s
    |
    ;
%%
void yyerror(){
    return;
}
int main(){
    printf("Enter input: ");
    yyparse();
    if(na == nb){
        printf("Valid\n");
    }
    else{
        printf("Invalid\n");
    }
    return 0;
}