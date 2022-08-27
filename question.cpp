#if SYSTEM == WINDOWS
    #define USE_CONIO_H true
#else
    #define USE_CONIO_H false
#endif

#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <conio.h>
#include "squaresolver.hpp"
#include "test.hpp"

void ask_question( const char *file_name, bool *session_continue )
{
    assert(file_name != NULL);
    assert(session_continue != NULL);

    if (USE_CONIO_H == true)
        request_for_windows(file_name, session_continue);
    else
        request_for_other_systems(file_name, session_continue);
}

void test( const char *file_name )
{
    assert(file_name != NULL);

    struct Test_data data[AMOUNT] = {};
    FILE *test_file = fopen(file_name, "r");

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
}

void interactive_quadratic_solver()
{
    printf("=============================\n");
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

void request_for_windows( const char *file_name, bool *session_continue )
{
    printf("press 'q' to quit, 't' to begin test or other key to start solving\n");

    char option = _getch();

    switch(option)
    {
        case 'q':
            *session_continue = false;
            break;
        case 't':
            test(file_name);
            break;
        default:
            interactive_quadratic_solver();
            break;
    }
}

void request_for_other_systems( const char *file_name, bool *session_continue )
{
    printf("press 'q' to quit, 't' to begin test or enter to start solving\n");

    char option = getchar();

    switch(option)
    {
        case 'q':
            if (getchar() != '\n')
            {
                end_of_iteration();
                break;
            }
            *session_continue = false;
            break;
        case 't':
            test(file_name);
            skip_line(stdin);
            break;
        case '\n':
            interactive_quadratic_solver();
            break;
        default:
            end_of_iteration();
            break;
    }
}

void end_of_iteration()
{
    skip_line(stdin);
    printf("\n");
}
