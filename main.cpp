#include <stdio.h>
#include "squaresolver.h"

int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    while (1)
    {
        printf("-----------------------------\n");
        printf("equation: a*x^2 + b*x + c = 0\n");
        if (input_coefficient(&a, &b, &c) == -1)
            continue;
        printer(squaresolver(a, b, c, &x1, &x2), &x1, &x2);
    }
    return 0;
}
