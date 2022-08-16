#include <stdio.h>
#include <stdlib.h>
#include "squaresolver.h"

int main()
{
    double *a, *b, *c, *x1, *x2;
    char *str;

    a = (double *)malloc(sizeof(double));
    b = (double *)malloc(sizeof(double));
    c = (double *)malloc(sizeof(double));

    x1 = (double *)malloc(sizeof(double));
    x2 = (double *)malloc(sizeof(double));

    str = (char *)malloc(sizeof(char));

    while (1)
    {
        printf("-----------------------------\n");
        printf("equation: a*x^2 + b*x + c = 0\n");
        if (input_coefficient(a, b, c) == -1)
            continue;
        printer(solver(a, b, c, x1, x2, str), x1, x2, str);
    }
    return 0;
}
