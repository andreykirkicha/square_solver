#include <math.h>
#include <stdio.h>
#include "squaresolver.hpp"

int squaresolver( double a, double b, double c, double *x1, double *x2 )
{
    if (x1 == NULL || x2 == NULL)
    {
        errno = PTR_NUL;
        return errno;
    }

    if (is_equal(a, 0, EPS))
        return linsolver(b, c, x1);
    else
    {
        if (is_equal(c, 0, EPS) && !is_equal(b, 0, EPS))
        {
            linsolver(a, b, x1);
            *x2 = 0;
            return TWO_ROOTS;
        }

        double D = b * b - 4 * a * c;

        if (D > 0)
        {
            double sqrtD = sqrt(D);

            *x1 = (-b - sqrtD) / (2 * a);
            *x2 = (-b + sqrtD) / (2 * a);
            return TWO_ROOTS;
        }
        else if (is_equal(D, 0, EPS))
        {
            *x1 = -b / (2 * a);
            return ONE_ROOT;
        }
        else
            return NO_ROOTS;
    }
}

int linsolver( double b, double c, double *x1 )
{
    if (x1 == NULL)
    {
        errno = PTR_NUL;
        return errno;
    }

    if (is_equal(b, 0, EPS))
        return (is_equal(c, 0, EPS)) ? INF_ROOTS : NO_ROOTS;
    else
    {
        *x1 = -c / b;
        return ONE_ROOT;
    }
}

int is_equal( double a, double b, double lim )
{
    return (fabs(a - b) < lim);
}
