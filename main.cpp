#include <stdio.h>
#include <conio.h>
#include "squaresolver.h"
#include "test.hpp"

struct IN in_str[AMOUNT] = {
    0, 0, 0,
    0, 1, 0,
    0, 0, 1,
    1, 2, 3,
    4999, 219, 78,
    -98, 6, 54,
    19, 27, 45,
    10, -25, 30,
    1, 9, 9,
    8, 8, 7
};

struct OUT out_str[AMOUNT] = {
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0
};

int main()
{
    while (1)
    {
        printf("<test>\n\n");
        test(in_str, out_str, AMOUNT);

        printf("press 'q' to quit or other key to start\n");
        char end_start = _getch();
        if (end_start == 'q')
            break;

        errno = 0;
        printf("---------------------------------------\n");
        printf("equation: a*x^2 + b*x + c = 0\n");

        double a = 0, b = 0, c = 0;
        if (input_coefficient(&a, &b, &c) == -1)
            continue;

        double x1 = 0, x2 = 0;
        double res = squaresolver(a, b, c, &x1, &x2);
        error_handler(errno);

        printer(res, x1, x2);
        printf("\n");
    }
    return 0;
}
