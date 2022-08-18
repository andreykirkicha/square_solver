#include <stdio.h>
#include <string.h>
#include <float.h>
#include "squaresolver.h"

void err(int n)
{
    char s[ERRLEN] = {};

    switch(n)
    {
        case 0:
            return;
        case -1:
        {
            char ch;
            printf("<error> ");
            while ((ch = getchar()) != '\n')
                putchar(ch);
            printf(" is not a number\n");
            return;
        }
        case -2:
        {
            strcpy(s, "some pointer is NULL");
            break;
        }
        case -3:
        {
            strcpy(s, "this number is too big");
            break;
        }
        case -4:
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
