#include <stdio.h>
#include <float.h>
#include "squaresolver.h"

int reader(double *a)
{
    if (a == NULL)
        errno = -2;
    else if (!scanf("%lf", a))
        errno = -1;
    else if (*a > FLT_MAX || *a < FLT_MIN)
        errno = -3;
    return errno;
}

int input_coefficient(double *a, double *b, double *c)
{
    printf("a = ");
    if (reader(a) != 0)
    {
        err(errno);
        return -1;
    }
    printf("b = ");
    if (reader(b) != 0)
    {
        err(errno);
        return -1;
    }
    printf("c = ");
    if (reader(c) != 0)
    {
        err(errno);
        return -1;
    }
    return 0;
}
