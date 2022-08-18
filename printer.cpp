#include <stdio.h>
#include <math.h>
#include "squaresolver.h"

void printer(int res, double x1, double x2)
{
    if (res < 0)
        return;
    printf("ans: ");
    if (res == TWO_ROOTS)
        printf("%lf, %lf\n", x1, x2);
    else if (res == ONE_ROOT)
    {
        if (fabs(x1) < EPS)
            x1 = 0;
        printf("%lf\n", x1);
    }
    else if (res == INF_ROOTS)
        printf("any number\n");
    else
        printf("nothing\n");
}
