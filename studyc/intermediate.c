#include <stdio.h>
#include <string.h>
char reg = 'Z';

void gen_code_for_op(char *input, char operator)
{
    int i = 0, j = 0;
    char temp[20];
    while (input[i] != '\0')
    {
        if (input[i] == operator)
        {
            printf("%c\t%c\t%c\t%c\n", operator, reg, input[i - 1], input[i + 1]);
            temp[j - 1] = reg;
            i += 2;
            reg--;
            continue;
        }
        temp[j] = input[i];
        i++;
        j++;
    }
    temp[++j] = '\0';
    strcpy(input, temp);
}
void main()
{
    char input[20];
    printf("Enter expression:\n");
    scanf("%s", input);
    printf("Operator Des\tOp1\tOp2\n");

    gen_code_for_op(input, '/');
    gen_code_for_op(input, '*');
    gen_code_for_op(input, '+');
    gen_code_for_op(input, '-');
    gen_code_for_op(input, '=');
}