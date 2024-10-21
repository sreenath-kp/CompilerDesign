/* Program to recognize components of a C program */
%{
int COMMENT = 0;
int cnt = 0;
%}

identifier [a-zA-Z][a-zA-Z0-9]*

%%

#.* { 
    printf("\n%s is a PREPROCESSOR DIRECTIVE", yytext); 
}

int |
float |
char |
double |
while |
for |
do |
if |
break |
continue |
void |
switch |
case |
long |
struct |
const |
typedef |
return |
else |
goto {
    printf("\n\t%s is a KEYWORD", yytext);
}

"/*" { 
    COMMENT = 1; 
}

"*/" { 
    COMMENT = 0; 
    cnt++; 
}

{identifier}\( { 
    if (!COMMENT) 
        printf("\n\nFUNCTION\n\t%s", yytext); 
}

\{ { 
    if (!COMMENT) 
        printf("\nBLOCK BEGINS"); 
}

\} { 
    if (!COMMENT) 
        printf("\nBLOCK ENDS"); 
}

{identifier}(\[[0-9]*\])? { 
    if (!COMMENT) 
        printf("\n%s is an IDENTIFIER", yytext); 
}

\".*\" { 
    if (!COMMENT) 
        printf("\n\t%s is a STRING", yytext); 
}

[0-9]+ { 
    if (!COMMENT) 
        printf("\n\t%s is a NUMBER", yytext); 
}

\)(\;)? { 
    if (!COMMENT) {
        printf("\n\t");
        ECHO; 
        printf("\n"); 
    }
}

\( {
    ECHO; 
}

= { 
    if (!COMMENT) 
        printf("\n\t%s is an ASSIGNMENT OPERATOR", yytext); 
}

\<= |
\>= |
\<  |
==  |
\> { 
    if (!COMMENT) 
        printf("\n\t%s is a RELATIONAL OPERATOR", yytext); 
}

%%

int main(int argc, char **argv) {
    yyin = fopen("input.txt", "r");
    yylex();
    fclose(yyin);
    printf("\n\nTotal Number of comments: %d\n", cnt);
    return 0;
}

int yywrap() {
    return 1;
}