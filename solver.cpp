#include <math.h>
#include "squaresolver.h"

int squaresolver(double a, double b, double c, double *x1, double *x2)
{
    if (a == 0)
        return linsolver(b, c, x1);
    else
    {
        double D = b * b - 4 * a * c;

        if (D > 0)
        {
            double sqrtD = sqrt(D);

            *x1 = (-b + sqrtD) / (2 * a);
            *x2 = (-b - sqrtD) / (2 * a);
            return TWO_ROOTS;
        }
        else if (D == 0)
        {
            *x1 = (-b) / (2 * a);
            return ONE_ROOT;
        }
        else
            return NO_ROOTS;
    }
}

int linsolver(double b, double c, double *x1)
{
    if (b == 0)
        return (c == 0) ? INF_ROOTS : NO_ROOTS;
    else
    {
        *x1 = - c / b;
        return ONE_ROOT;
    }
}
