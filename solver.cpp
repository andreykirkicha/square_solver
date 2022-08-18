#include <math.h>
#include <stdio.h>
#include <float.h>
#include "squaresolver.h"

int squaresolver(double a, double b, double c, double *x1, double *x2)
{
    if (x1 == NULL || x2 == NULL)
    {
        errno = PTR_NULL;
        return errno;
    }

    if (cmp_double(a, 0, EPS))
        return linsolver(b, c, x1);
    else
    {
        if (not_in_range(b * b - 4 * a * c))
        {
            errno = TOO_BIG_CALC;
            return errno;
        }

        double D = b * b - 4 * a * c;

        if (D > 0)
        {
            double sqrtD = sqrt(D);

            if (not_in_range((-b + sqrtD) / (2 * a)) || not_in_range((-b - sqrtD) / (2 * a)))
            {
                errno = TOO_BIG_CALC;
                return errno;
            }

            *x1 = (-b + sqrtD) / (2 * a);
            *x2 = (-b - sqrtD) / (2 * a);
            return TWO_ROOTS;
        }
        else if (cmp_double(D, 0, EPS))
        {
            if (not_in_range((-b) / (2 * a)))
            {
                errno = TOO_BIG_CALC;
                return errno;
            }

            *x1 = (-b) / (2 * a);
            return ONE_ROOT;
        }
        else
            return NO_ROOTS;
    }
}

int linsolver(double b, double c, double *x1)
{
    if (x1 == NULL)
    {
        errno = PTR_NULL;
        return errno;
    }

    if (cmp_double(b, 0, EPS))
        return (cmp_double(c, 0, EPS)) ? INF_ROOTS : NO_ROOTS;
    else
    {
        if (not_in_range(- c / b))
        {
            errno = TOO_BIG_CALC;
            return errno;
        }

        *x1 = - c / b;
        return ONE_ROOT;
    }
}

int cmp_double(double a, double b, double lim)
{
    if (fabs(a - b) < lim)
        return 1;
    return 0;
}
