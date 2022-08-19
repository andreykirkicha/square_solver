#include <stdio.h>
#include <string.h>
#include <float.h>
#include "squaresolver.h"

void error_handler(int error)
{
    char message[ERRLEN] = {};

    switch(error)
    {
        case 0:
            return;
        case NOT_NUM:
        {
            char sym = '0';
            printf("<error> ");
            while ((sym = getchar()) != '\n')
                putchar(sym);
            printf(" is not a number\n");
            return;
        }
        case PTR_NULL:
        {
            strcpy(message, "some pointer is NULL");
            break;
        }
        case TOO_BIG:
        {
            strcpy(message, "this number is too big");
            break;
        }
        case TOO_BIG_CALC:
        {
            strcpy(message, "overflow during calculation");
            break;
        }
        case INF_NAN:
        {
            strcpy(message, "inappropriate value");
            break;
        }
        case TOO_MANY:
        {
            strcpy(message, "too many arguments");
            break;
        }
        default:
        {
            strcpy(message, "unknown error");
            break;
        }
    }

    printf("<error> %s\n", message);
    return;
}

int not_in_range(double num)
{
    if (num < -DBL_MAX || num > DBL_MAX)
        return 1;
    return 0;
}
