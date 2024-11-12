%{
    #include <stdio.h>
    #include <stdlib.h>
    int words = 0;
%}

%%
"the" { words++; } 
.|\n     ;    
%%

int yywrap() {
    return 1;  
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (!fp) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }
    
    yyin = fp;
    yylex();
    printf("The count: %d\n", words);

    fclose(fp);
    return 0;
}
