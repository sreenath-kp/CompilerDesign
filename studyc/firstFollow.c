#include <stdio.h>
#include <string.h>
#include <ctype.h>

int productionCount;
char productions[10][10], result[10];
int resultIndex = 0;

void findFirst(char symbol);
void findFollow(char symbol);

int main()
{
    int continueFlag;
    char targetSymbol, tempChar;

    printf("Enter the number of productions:\n");
    scanf("%d", &productionCount);

    printf("Enter the productions:\n");
    for (int i = 0; i < productionCount; i++)
    {
        scanf("%s%c", productions[i], &tempChar); // Input each production rule
    }

    do
    {
        resultIndex = 0;

        printf("Enter the symbol to find First and Follow sets: ");
        scanf(" %c", &targetSymbol); // Note the space before %c to capture newline

        // Calculate First set
        findFirst(targetSymbol);
        printf("First(%c) = { ", targetSymbol);
        for (int i = 0; i < resultIndex; i++)
            printf("%c ", result[i]);
        printf("}\n");

        // Reset result array for Follow set calculation
        strcpy(result, " ");
        resultIndex = 0;

        // Calculate Follow set
        findFollow(targetSymbol);
        printf("Follow(%c) = { ", targetSymbol);
        for (int i = 0; i < resultIndex; i++)
            printf("%c ", result[i]);
        printf("}\n");

        printf("Continue? (1 for Yes / 0 for No): ");
        scanf("%d%c", &continueFlag, &tempChar);
    } while (continueFlag == 1);

    return 0;
}

// Function to find the First set of a given symbol
void findFirst(char symbol)
{
    // If the symbol is a terminal, add it to result and return
    if (!isupper(symbol))
    {
        result[resultIndex++] = symbol;
        return;
    }

    // For non-terminals, examine each production
    for (int i = 0; i < productionCount; i++)
    {
        if (productions[i][0] == symbol)
        { // Match production with target symbol on LHS
            if (productions[i][2] == '$')
            { // If production is a nullable production
                findFollow(productions[i][0]);
            }
            else if (islower(productions[i][2]))
            { // If production begins with terminal
                result[resultIndex++] = productions[i][2];
            }
            else
            { // If production begins with non-terminal
                findFirst(productions[i][2]);
            }
        }
    }
}

// Function to find the Follow set of a given symbol
void findFollow(char symbol)
{
    // Add '$' to Follow set of the start symbol
    if (productions[0][0] == symbol)
    {
        result[resultIndex++] = '$';
    }

    // Check each production to see if the symbol appears
    for (int i = 0; i < productionCount; i++)
    {
        for (int j = 2; j < strlen(productions[i]); j++)
        {
            if (productions[i][j] == symbol)
            {
                // If symbol is followed by another symbol, add its First to Follow
                if (productions[i][j + 1] != '\0')
                {
                    findFirst(productions[i][j + 1]);
                }

                // If symbol is at end, add Follow of LHS symbol to its Follow
                if (productions[i][j + 1] == '\0' && symbol != productions[i][0])
                {
                    findFollow(productions[i][0]);
                }
            }
        }
    }
}
