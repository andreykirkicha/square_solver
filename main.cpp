#include <stdio.h>
#include <conio.h>
#include "squaresolver.h"
#include "test.hpp"

struct IN in_str[AMOUNT] = {
    0, 0, 0,
    0, 1, 0,
    0, 0, 1,
    1, -2, 1,
    4999, 219, 78,
    -98, 6, 54,
    19, 27, 45,
    10, -25, 30,
    1, 9, 9,
    3, 8, -7
};

struct ANS ans_str[AMOUNT] = {
    -27, -27, "any number",
    0, -27, "one root",
    -27, -27, "nothing",
    1, -27, "one root",
    -27, -27, "nothing",
    -0.712326, 0.773551, "two roots",
    -27, -27, "nothing",
    -27, -27, "nothing",
    -7.854102, -1.145900, "two roots",
    -3.360920, 0.694254, "two roots"
};

struct OUT out_str[AMOUNT] = {
    -27, -27, -27,
    -27, -27, -27,
    -27, -27, -27,
    -27, -27, -27,
    -27, -27, -27,
    -27, -27, -27,
    -27, -27, -27,
    -27, -27, -27,
    -27, -27, -27,
    -27, -27, -27
};

int main()
{
    printf("<test>\n\n");
    test(in_str, out_str, ans_str, AMOUNT);

    while (1)
    {
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
