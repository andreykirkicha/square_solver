#include <stdio.h>
#include <conio.h>
#include "squaresolver.h"
#include "test.hpp"

struct IN in_str[AMOUNT] = {
    START_VAL, START_VAL, START_VAL,
    START_VAL, START_VAL, START_VAL,
    START_VAL, START_VAL, START_VAL,
    START_VAL, START_VAL, START_VAL,
    START_VAL, START_VAL, START_VAL,
    START_VAL, START_VAL, START_VAL,
    START_VAL, START_VAL, START_VAL,
    START_VAL, START_VAL, START_VAL,
    START_VAL, START_VAL, START_VAL,
    START_VAL, START_VAL, START_VAL
};

struct ANS ans_str[AMOUNT] = {
    START_VAL, START_VAL, "any number",
    START_VAL, START_VAL, "nothing",
    0, START_VAL, "one root",
    -0.8, 0, "two roots",
    START_VAL, START_VAL, "incorrect input",
    START_VAL, START_VAL, "incorrect input",
    START_VAL, START_VAL, "incorrect input",
    START_VAL, START_VAL, "incorrect input",
    -1.538284, 0.420637, "two roots",
    -9.361823, 10.782875, "two roots"
};

struct OUT out_str[AMOUNT] = {
    START_VAL, START_VAL, START_VAL,
    START_VAL, START_VAL, START_VAL,
    START_VAL, START_VAL, START_VAL,
    START_VAL, START_VAL, START_VAL,
    START_VAL, START_VAL, START_VAL,
    START_VAL, START_VAL, START_VAL,
    START_VAL, START_VAL, START_VAL,
    START_VAL, START_VAL, START_VAL,
    START_VAL, START_VAL, START_VAL,
    START_VAL, START_VAL, START_VAL
};

int main()
{
    errno = OK;
    FILE *f = fopen("test.txt", "r");

    printf("<test>\n\n");
    test(in_str, out_str, ans_str, AMOUNT, errno, f);

    while (1)
    {
        printf("press 'q' to quit or other key to start\n");
        char end_start = _getch();
        if (end_start == 'q')
            break;

        errno = OK;
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
