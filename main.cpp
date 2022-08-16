#include <stdio.h>
#include <stdlib.h>
#include "squaresolver.h"

int main()
{
    double a, b, c, x1, x2;

    while (1)
    {
        printf("-----------------------------\n");
        printf("equation: a*x^2 + b*x + c = 0\n");
        if (input_coefficient(&a, &b, &c) == -1)
            continue;
        printer(squaresolver(&a, &b, &c, &x1, &x2), &x1, &x2);
    }
    return 0;
}
