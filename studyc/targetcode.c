#include <stdio.h>
#include <string.h>

void main()
{
    char intercode[10][10], str[20], opr[10];
    int i = 0;
    printf("\nEnter the set of intermediate code (terminated by 'exit'):\n");
    do
    {
        scanf("%s", intercode[i]);
    } while (strcmp(intercode[i++], "exit") != 0);

    printf("Target code generation\n");
    i = 0;
    do
    {
        strcpy(str, intercode[i]);
        switch (str[3])
        {
        case '+':
            strcpy(opr, "ADD");
            break;
        case '-':
            strcpy(opr, "SUB");
            break;
        case '*':
            strcpy(opr, "MUL");
            break;
        case '/':
            strcpy(opr, "DIV");
            break;
        }
        printf("\nMOV %c,R%d", str[2], i);
        printf("\n%s %c,R%d", opr, str[4], i);
        printf("\nMov R%d,%c", i, str[0]);

    } while (strcmp(intercode[++i], "exit") != 0);
    printf("\n");
}

// input is of the form
// a=b+c
// d=c*3