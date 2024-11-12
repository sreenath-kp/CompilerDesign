#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct exp
{
    char op[2], op1[5], op2[5], res[5];
    int flag;
} arr[10];

void change(int p, char *folded);

int n;
int main()
{
    printf("Enter no of expressions\n");
    scanf("%d", &n);
    printf("Enter expressions\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i].op);
        scanf("%s", arr[i].op1);
        scanf("%s", arr[i].op2);
        scanf("%s", arr[i].res);
        arr[i].flag = 0;
    }
    char constnat[5];

    for (int i = 0; i < n; i++)
    {
        if ((isdigit(arr[i].op1[0]) && isdigit(arr[i].op2[0])) || strcmp(arr[i].op, "=") == 0)
        {
            int op1 = atoi(arr[i].op1);
            int op2 = atoi(arr[i].op2);
            char op = arr[i].op[0];
            int res;
            switch (op)
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/':
                res = op1 / op2;
                break;
            case '=':
                res = op1;
                break;
            default:
                break;
            }

            sprintf(constnat, "%d", res);
            arr[i].flag = 1;
            change(i, constnat);
        }
    }
    printf("\nOptimized code is:\n");
    for (int i = 0; i < n; i++)
    {
        if (!arr[i].flag)
        {
            printf("%s %s %s %s\n", arr[i].op, arr[i].op1, arr[i].op2, arr[i].res);
        }
    }
}
void change(int p, char *constnat)
{
    for (int i = p + 1; i < n; i++)
    {
        if (strcmp(arr[p].res, arr[i].op1) == 0)
            strcpy(arr[i].op1, constnat);
        else if (strcmp(arr[p].res, arr[i].op2) == 0)
            strcpy(arr[i].op2, constnat);
    }
}