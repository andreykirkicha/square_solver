#include <stdio.h>
#include <math.h>

int solver(double *a, double *b, double *c, double *x1, double *x2, char *str)
{
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                sprintf(str, "%s", "any number");
                return 0;
            }
            else
            {
                sprintf(str, "%s", "nothing");
                return -1;
            }
        }
        else
        {
            *x1 = - (*c) / (*b);
            return 1;
        }
    }
    else
    {
        double D = (*b) * (*b) - 4 * (*a) * (*c);
        if (D > 0)
        {
            *x1 = (-(*b) + sqrt(D)) / (2 * (*a));
            *x2 = (-(*b) - sqrt(D)) / (2 * (*a));
            return 2;
        }
        else if (D == 0)
        {
            *x1 = (-(*b)) / (2 * (*a));
            return 1;
        }
        else
        {
            sprintf(str, "%s", "nothing");
            return -1;
        }
    }
}
