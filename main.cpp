#include <stdio.h>
#include <conio.h>
#include "squaresolver.hpp"
#include "test.hpp"

struct TEST_DATA data[AMOUNT] = {
    START_VAL, START_VAL, START_VAL, START_VAL, START_VAL, "",
    START_VAL, START_VAL, START_VAL, START_VAL, START_VAL, "",
    START_VAL, START_VAL, START_VAL, START_VAL, START_VAL, "",
    START_VAL, START_VAL, START_VAL, START_VAL, START_VAL, "",
    START_VAL, START_VAL, START_VAL, START_VAL, START_VAL, "",
    START_VAL, START_VAL, START_VAL, START_VAL, START_VAL, "",
    START_VAL, START_VAL, START_VAL, START_VAL, START_VAL, "",
    START_VAL, START_VAL, START_VAL, START_VAL, START_VAL, "",
    START_VAL, START_VAL, START_VAL, START_VAL, START_VAL, "",
    START_VAL, START_VAL, START_VAL, START_VAL, START_VAL, ""
};

int main()
{
    errno = OK;
    FILE *f = fopen("test.txt", "r");
    int i = 0;

    printf("<test_begin>\n\n");
    for ( ; i < AMOUNT; i++)
        test(&data[i], i, f);
    printf("<test_end>\n\n");

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
