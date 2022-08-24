#include <stdio.h>
#include <math.h>
#include "squaresolver.hpp"

int reader( double *a )
{
    if (a == NULL)
    {
        errno = PTR_NUL;
        return errno;
    }

    if (!scanf("%lf", a) || !finite(*a))
    {
        errno = INC_INP;
        return errno;
    }

    char tail = getchar();
    if (tail != '\n')
        errno = INC_INP;

    return errno;
}

int input_coefficient( double *a, double *b, double *c )
{
    printf("a = ");
    if (reader(a) != 0)
    {
        error_handler(errno);
        return -1;
    }

    printf("b = ");
    if (reader(b) != 0)
    {
        error_handler(errno);
        return -1;
    }

    printf("c = ");
    if (reader(c) != 0)
    {
        error_handler(errno);
        return -1;
    }
    return 0;
}

void printer( int res, double x1, double x2 )
{
    switch(res)
    {
        case TWO_ROOTS:
        {
            printf("%lf, %lf\n", x1, x2);
            break;
        }
        case ONE_ROOT:
        {
            if (is_equal(x1, 0, EPS))
                x1 = 0;
            printf("%lf\n", x1);
            break;
        }
        case INF_ROOTS:
        {
            printf("any number\n");
            break;
        }
        case NO_ROOTS:
        {
            printf("nothing\n");
            break;
        }
        default:
        {
            printf("unexpected number of roots\n");
            break;
        }
    }
    return;
}
