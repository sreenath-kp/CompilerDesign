%{
    #include "y.tab.h"
    #include <stdio.h>
%}

%token NUMBER
%left '+'  '-'
%left '*'  '/'
%right '^'

%%

S: E '\n' { printf("\n"); }
      | /* empty */
      ;

E   : E '+' E { printf("+ "); }
    | E '-' E { printf("- "); }
    | E '*' E { printf("* "); }
    | E '/' E { printf("/ "); }
    | '(' E ')' { /* Do nothing, just evaluate inner expression */ }
    | NUMBER { printf("%d ", yylval); }
    ;

%%

void yyerror() {
    printf("Error");
    return 0;
}

int main(void) {
    printf("Enter the infix expression: ");
    yyparse();
    return 0;
}
