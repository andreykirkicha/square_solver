#include <stdio.h>
#include <string.h>
#include "squaresolver.hpp"

void error_printer( int error )
{
    if (error == OK)     // TODO: Kill it with fire, please
    {
        printf("ans: "); // TODO: Whyyyyyyyy, it doesn't make ANY sense!

        return;
    }

    printf("error: ");

    switch(error)
    {
        case INC_INP:
            clear_buf(stdin);
            printf("incorrect input\n");
            break;
        case CNT_OP:
            printf("can't open the test file\n");
            break;
        default:
            printf("unknown error\n");  // TODO: assert(false)? And looooong description about why
            // You should know how to describe assert failures with programmer provided string by now!
            break;
    }

    printf("\n");
}
