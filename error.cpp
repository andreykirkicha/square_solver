#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "solver.hpp"
#include "interface.hpp"
#include "error.hpp"

void error_printer( int error )
{
    if (error == NO_ERROR)
        return;

    printf("error: ");

    switch(error)
    {
        case INCORRECT_INPUT:
            skip_line(stdin);
            printf("Incorrect input\n");
            break;
        default:
            assert(false && "unknown error\n");
            break;
    }

    printf("\n");
}
