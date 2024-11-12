#include <stdio.h>
#include <string.h>

char a[20];
char reduce[20], stack[20], act[20];
int c = 0, k, i, j = 0;
void check();
int main()
{

    printf("Grammer is:\n E->E+E \n E->E*E \n E->(E) \n E->id\n");
    printf("Enter input string: ");
    scanf("%s", a);
    c = strlen(a);
    strcpy(act, "SHIFT->");
    puts("Stack\tInput\tAction");
    for (i = 0; j < c; i++, j++)
    {
        if (a[j] == 'i' && a[j + 1] == 'd')
        {
            stack[i] = a[j];
            stack[i + 1] = a[j + 1];
            stack[i + 2] = '\0';
            a[j] = ' ';
            a[j + 1] = ' ';
            printf("\n$%s\t%s$\t%sid", stack, a, act);
            check();
        }
        else
        {
            stack[i] = a[j];
            stack[i + 1] = '\0';
            a[j] = ' ';
            printf("\n$%s\t%s$\t%ssymbols", stack, a, act);
            check();
        }
    }
    printf("\n");
}

void check()
{
    strcpy(reduce, "REDUCE TO E");
    for (int k = 0; k < c; k++)
    {
        if (stack[k] == 'i' && stack[i + 1] == 'd')
        {
            stack[k] = 'E';
            stack[k + 1] = '\0';
            printf("\n$%s\t%s$\t%s", stack, a, reduce);
            j++;
        }
    }
    for (k = 0; k < c; k++)
        if (stack[k] == 'E' && stack[k + 1] == '+' && stack[k + 2] == 'E')
        {
            stack[k] = 'E';
            stack[k + 1] = '\0';
            stack[k + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stack, a, reduce);
            i = i - 2;
        }
    for (k = 0; k < c; k++)
        if (stack[k] == 'E' && stack[k + 1] == '*' && stack[k + 2] == 'E')
        {
            stack[k] = 'E';
            stack[k + 1] = '\0';
            stack[k + 1] = '\0';
            printf("\n$%s\t%s$\t%s", stack, a, reduce);
            i = i - 2;
        }
    for (k = 0; k < c; k++)
        if (stack[k] == '(' && stack[k + 1] == 'E' && stack[k + 2] == ')')
        {
            stack[k] = 'E';
            stack[k + 1] = '\0';
            stack[k + 1] = '\0';
            printf("\n$%s\t%s$\t%s", stack, a, reduce);
            i = i - 2;
        }
}
