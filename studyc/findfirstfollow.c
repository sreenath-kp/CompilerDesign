#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n;
char result[10], production[10][10];

void first(char c);
void follow(char c);
void main()
{
    char c, ch;
    printf("Enter no of productions\n");
    scanf("%d", &n);

    printf("Enter the productions:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s%c", production[i], &ch);
    }
    int yes = 0;
    do
    {
        printf("Enter the element whose first and follow need to be found:");
        scanf("%c", &c);
        printf("First(%c) : {", c);
        first(c);
        printf("}\n");
        printf("Follow(%c) : {", c);
        follow(c);
        printf("}\n");
        printf("Continue (0/1)? ");
        scanf("%d%c", &yes, &ch);
    } while (yes);
}

void first(char c)
{
    if (islower(c))
    {
        printf(" %c ", c);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (production[i][0] == c)
            if (production[i][2] == '$')
                follow(production[i][0]);
            else if (islower(production[i][2]))
                printf(" %c ", production[i][2]);
            else
                first(production[i][2]);
    }
}

void follow(char c)
{
    if (production[0][0] == c)
        printf(" %c ", '$');
    for (int i = 0; i < n; i++)
        for (int j = 2; j < strlen(production[i]); j++)
            if (production[i][j] == c)
            {
                if (production[i][j + 1] != '\0')
                    first(production[i][j + 1]);
                if (production[i][j + 1] == '\0' && c != production[i][0])
                    follow(production[i][0]);
            }
}