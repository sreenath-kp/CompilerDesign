#include <stdio.h>
#include <string.h>

char str[51], st[50];
int top = -1;

void push(char c)
{
    st[++top] = c;
    st[top + 1] = '\0';
}

void pop(int n)
{
    top -= n;
    st[top + 1] = '\0';
}

void check()
{
    int reduced = 1;
    while (reduced)
    {
        reduced = 0;
        if (top > 0 && st[top - 1] == 'i' && st[top] == 'd')
        { // Check for "id" at the top of the stack only
            pop(2);
            push('E');
            printf("\n$%s\t%s$\t%s", st, str, "REDUCE TO E");
            reduced = 1;
        }
        else if (top >= 2)
        { // Check for patterns "E+E", "E*E", and "(E)" at the top of the stack only
            if ((st[top - 2] == 'E' && st[top - 1] == '+' && st[top] == 'E') ||
                (st[top - 2] == 'E' && st[top - 1] == '*' && st[top] == 'E') ||
                (st[top - 2] == '(' && st[top - 1] == 'E' && st[top] == ')'))
            {
                pop(3);
                push('E');
                printf("\n$%s\t%s$\t%s", st, str, "REDUCE TO E");
                reduced = 1;
            }
        }
    }
}

void main()
{
    printf("GRAMMAR\nE->E+E \nE->E*E \nE->(E) \nE->id\n");
    printf("Enter input string: ");
    scanf("%s", str);

    printf("\nstack \t Input \t\t Action");
    printf("\n$\t%s$\t", str);

    for (int j = 0; j < strlen(str); j++)
    {
        if (str[j] == 'i' && str[j + 1] == 'd')
        {
            push('i');
            push('d');
            str[j] = ' ';
            str[j + 1] = ' ';
            j++;
            printf("\n$%s\t%s$\t%s id", st, str, "SHIFT ->");
            check();
        }
        else
        {
            push(str[j]);
            printf("\n$%s\t%s$\t%s %c", st, str, "SHIFT ->", str[j]);
            str[j] = ' ';
            check();
        }
    }
    if (top == 0 && st[top] == 'E')
        printf("\n\nParsing Successful!");
    else
        printf("\n\nParsing Failed!");
}