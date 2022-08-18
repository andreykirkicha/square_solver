#include <stdio.h>
#include <float.h>
#include <math.h>
#include "squaresolver.h"

int reader(double *a)
{
    if (a == NULL)
        errno = PTR_NULL;

    else if (!scanf("%lf", a))
        errno = NOT_NUM;

    else if (limits(*a))
        errno = TOO_BIG;

    return errno;
}

int input_coefficient(double *a, double *b, double *c)
{
    printf("a = ");
    if (reader(a) != 0)
    {
        errorhunter(errno);
        return -1;
    }

    printf("b = ");
    if (reader(b) != 0)
    {
        errorhunter(errno);
        return -1;
    }

    printf("c = ");
    if (reader(c) != 0)
    {
        errorhunter(errno);
        return -1;
    }

    return 0;
}

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
