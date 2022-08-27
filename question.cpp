#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "squaresolver.hpp"
#include "test.hpp"

void ask_question( char *argv[], bool *session ) // ask_question give_answer solve_linear
{
    assert(session != NULL);

    // TODO: tests are ONLY intended for programmer, user shouldn't have
    // option to run them (it's too scary for most users, and useless anyway)

    // To accomplish this you can have two different files with main()
    // one for interactive use, and other for running tests.

    // This would imply manual use of compiler instead of Code::Blocks
    // which is a very good thing for learning!

    printf("press 'q' to quit, 't' to begin test or enter to start solving\n");
    char option = getchar();

    switch(option)
    {
        case 'q':
            *session = END;
            break;
        case 't':
            test(argv); // TODO: pass only what's needed (ergo, const char* test_file_name)
            break;
        case '\n':
            input_calculate_output();
            break;
        default:
            printf("\n");
            clear_buf(stdin);
            break;
    }
}

// TODO: change signature, TODO next to this function's usage explains this in detail
void test( char *argv[] ) // TODO: we already have TODO for project structure (splitting in different headers)
                          // but this definitely belongs in test.hpp
{
    struct TEST_DATA data[AMOUNT] = {};
    FILE *test_file = fopen(argv[1], "r");

    if (test_file == NULL)
    {
        // TODO: Can you use perror to describe reason for failure?
        error_printer(CNT_OP);

        return;
    }

    printf("\n<test_begin>\n\n");
    for (int i = 0; i < AMOUNT; i++)
        test_calculate(&data[i], i, test_file);
    printf("<test_end>\n\n");

    clear_buf(stdin);
}

void input_calculate_output() // TODO: rename to something like interactive_quadractic_solver()
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

    printf("ans: "); // Somehow this is not error_printer and it shouldn't be, good job!
    printer(res, x1, x2);
    printf("\n");
}
