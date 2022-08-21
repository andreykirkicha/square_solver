#include <stdio.h>
#include <string.h>
#include <float.h>
#include "squaresolver.hpp"

void error_handler(int error)
{
    if (error == OK)
    {
        printf("ans: ");
        return;
    }

    printf("error: ");

    switch(error)
    {
        case INC_INP:
        {
            char sym = '0';
            while ((sym = getchar()) != '\n')
                ;
            printf("incorrect input\n");
            break;
        }
        case PTR_NUL:
        {
            printf("some pointer is NULL\n");
            break;
        }
        default:
        {
            printf("unknown error\n");
            break;
        }
    }
    printf("\n");
    return;
}
