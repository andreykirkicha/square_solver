#include <stdio.h>
#include <string.h>
#include <float.h>
#include "squaresolver.h"

void errorhunter(int n)
{
    char s[ERRLEN] = {};

    switch(n)
    {
        case 0:
            return;
        case NOT_NUM:
        {
            char ch = '0';
            printf("<error> ");
            while ((ch = getchar()) != '\n')
                putchar(ch);
            printf(" is not a number\n");
            return;
        }
        case PTR_NULL:
        {
            strcpy(s, "some pointer is NULL");
            break;
        }
        case TOO_BIG:
        {
            strcpy(s, "this number is too big");
            break;
        }
        case TOO_BIG_CALC:
        {
            strcpy(s, "overflow during calculation");
            break;
        }
        default:
        {
            strcpy(s, "unknown error");
            break;
        }
    }

    printf("<error> %s\n", s);
    return;
}

int limits(double n)
{
    if (n < -DBL_MAX || n > DBL_MAX)
        return 1;
    return 0;
}
