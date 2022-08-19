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
        {
            printf("ans: ");
            return;
        }
        case INC_INP:
        {
            char sym = '0';
            while ((sym = getchar()) != '\n')
                ;
            strcat(message, "incorrect input");
            break;
        }
        case PTR_NULL:
        {
            strcpy(message, "some pointer is NULL");
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
