#include <stdio.h>
#include <conio.h>
#include "squaresolver.hpp"
#include "test.hpp"

struct TEST_DATA data[AMOUNT] = {};

int main(int argc, char *argv[])
{
    while (1)
    {
        printf("press 'q' to quit, 't' to begin test or other key to start solving\n");
        char end_start = _getch();
        if (end_start == 'q')
            break;

        errno = OK;

        if (end_start == 't')
        {
            FILE *f = fopen(argv[1], "r");
            if (f == NULL)
            {
                errno = CNT_OP;
                error_handler(errno);
                continue;
            }
            int i = 0;

            printf("\n<test_begin>\n\n");
            for ( ; i < AMOUNT; i++)
                test(&data[i], i, f);
            printf("<test_end>\n\n");
            continue;
        }

        printf("------------------------------------------------------------------\n");
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
