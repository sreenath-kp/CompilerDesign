%{
    extern int yylval;
    #include "y.tab.h"
    #include <stdlib.h>
%}

%%

[0-9]+          { yylval = atoi(yytext); return NUMBER; }  // Convert to double for `yylval` 
[ \t]+          ;       // Ignore whitespace
.               { return yytext[0]; }  // Return individual characters for operators and parentheses
\n              { return '\n'; }     // Return newline to signal end of line

%%

int yywrap() {
    return 1;
}
