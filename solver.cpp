#include <math.h>
#include <stdio.h>
#include <float.h>
#include "squaresolver.h"

int squaresolver(double a, double b, double c, double *x1, double *x2)
{
    if (x1 == NULL || x2 == NULL)
    {
        errno = -2;
        return errno;
    }
    if (fabs(a) < EPS)
        return linsolver(b, c, x1);
    else
    {
        if (limits(b * b - 4 * a * c))
        {
            errno = -4;
            return errno;
        }

        double D = b * b - 4 * a * c;

        if (D > 0)
        {
            double sqrtD = sqrt(D);

            if (limits((-b + sqrtD) / (2 * a)) || limits((-b - sqrtD) / (2 * a)))
            {
                errno = -4;
                return errno;
            }

            *x1 = (-b + sqrtD) / (2 * a);
            *x2 = (-b - sqrtD) / (2 * a);
            return TWO_ROOTS;
        }
        else if (fabs(D) < EPS)
        {
            if (limits((-b) / (2 * a)))
            {
                errno = -4;
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
        errno = -2;
        return errno;
    }

    if (fabs(b) < EPS)
        return (fabs(c) < EPS) ? INF_ROOTS : NO_ROOTS;
    else
    {
        if (limits(- c / b))
        {
            errno = -4;
            return errno;
        }

        *x1 = - c / b;
        return ONE_ROOT;
    }
}
