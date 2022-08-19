#include <stdio.h>
#include "squaresolver.h"

int main()
{
    while (1)
    {
        errno = 0;
        printf("-----------------------------\n");
        printf("equation: a*x^2 + b*x + c = 0\n");

        double a = 0, b = 0, c = 0;
        if (input_coefficient(&a, &b, &c) == -1)
            continue;

        double x1 = 0, x2 = 0;
        double res = squaresolver(a, b, c, &x1, &x2);
        error_handler(errno);

        printer(res, x1, x2);
    }
    return 0;
}
