#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include "squaresolver.hpp"
#include "test.hpp"

void ask_question( const char *file_name, bool *session )
{
    assert(file_name != NULL);
    assert(session != NULL);

    printf("press 'q' to quit, 't' to begin test or enter to start solving\n");
    char option = getchar();

    switch(option)
    {
        case 'q':
            *session = END;
            break;
        case 't':
            test(file_name);
            break;
        case '\n':
            interactive_quadratic_solver();
            break;
        default:
            printf("\n");
            skip_line(stdin);
            break;
    }
}

void test( const char *file_name )
{
    struct Test_data data[AMOUNT] = {};
    FILE *test_file = fopen(file_name, "r");

    assert(file_name != NULL);

    if (test_file == NULL)
    {
        perror("error");
        printf("\n");

        return;
    }

    printf("\n<test_begin>\n\n");
    for (int i = 0; i < AMOUNT; i++)
        test_calculate(&data[i], i, test_file);
    printf("<test_end>\n\n");

    skip_line(stdin);
}

void interactive_quadratic_solver()
{
    printf("--------------------------------------------------------------\n");
    printf("equation: a*x^2 + b*x + c = 0\n");

    double a = 0;
    double b = 0;
    double c = 0;

    if (input_coefficients(&a, &b, &c) == FAILED)
        return;

    double x1 = 0;
    double x2 = 0;
    double res = square_solver(a, b, c, &x1, &x2);

    printf("ans: ");
    print_solution(res, x1, x2);
    printf("\n");
}
