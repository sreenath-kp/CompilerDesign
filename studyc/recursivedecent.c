#include <stdio.h>
#include <string.h>

char input[15], ptr = 0, op[50], temp[50];
void e_prime();
void e();
void t_prime();
void t();
void f();
void advance();

void e()
{
    strcpy(op, "TE'");
    printf("E=%-25s", op);
    printf("E->TE'\n");
    t();
    e_prime();
}
void e_prime()
{
    
}