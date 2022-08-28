#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "test.hpp"
#include "solver.hpp"
#include "interface.hpp"
#include "error.hpp"

Errors test_print( struct Test_data *test, int num, FILE *f, int *test_count, int *correct_test_count )
{
    assert(test != NULL);
    assert(finite(num));
    assert(f != NULL);

    double x1 = 0;
    double x2 = 0;

    Errors error = test_read(test, f);

    printf("%d)", num + 1);

    if (error == INCORRECT_INPUT)
    {
        skip_line(f);
        int res = error;

        printf("\tinput:\n\tincorrect input\n\n"
               "\toutput:\n\tres:\t%d\n\n",
               res);
    }

    else
    {
        int res = square_solver(test->a, test->b, test->c, &x1, &x2);

        printf("\tinput:\n\ta:\t%lf\n\tb:\t%lf\n\tc:\t%lf\n\n",
            test->a, test->b, test->c);

        switch(res)
        {
            case INF_ROOTS:
            case NO_ROOTS:
                printf("\toutput:\n\tres:\t%d\n\n"
                    "\twanted:\n\tans:\t%s\n\n",
                    res,
                    test->res);
                break;

            case ONE_ROOT:
                printf("\toutput:\n\tres:\t%d\n\tx1:\t%lf\n\n"
                    "\twanted:\n\tans:\t%s\n\tx1:\t%lf\n\n",
                    res, x1,
                    test->res, test->x1);

                if (is_equal(x1, test->x1))
                {
                    printf("\tNO_ERROR\n\n");
                    (*correct_test_count)++;
                }

                else
                    printf("\tFAILED\n\n");
                (*test_count)++;
                break;

            case TWO_ROOTS:
                printf("\toutput:\n\tres:\t%d\n\tx1:\t%lf\n\tx2:\t%lf\n\n"
                    "\twanted:\n\tans:\t%s\n\tx1:\t%lf\n\tx2:\t%lf\n\n",
                    res, x1, x2,
                    test->res, test->x1, test->x2);

                if (is_equal(x1, test->x1) && is_equal(x2, test->x2))
                {
                    printf("\tNO_ERROR\n\n");
                    (*correct_test_count)++;
                }

                else
                    printf("\tFAILED\n\n");
                (*test_count)++;
                break;
        }
    }

    return error;
}

Errors test_read( struct Test_data *test, FILE *f )
{
    assert(test != NULL);
    assert(f != NULL);

    if (fscanf(f, "%lf %lf %lf %lf %lf %s", &(test->a), &(test->b), &(test->c),
        &(test->x1), &(test->x2), test->res) != ARGUMENTS_NUMBER ||
        !finite(test->a) || !finite(test->b) || !finite(test->c))
        return INCORRECT_INPUT;

    char tail = getc(f);

    if (tail != '\n')
        return INCORRECT_INPUT;

    return NO_ERROR;
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

    int test_count = 0;
    int correct_test_count = 0;

    for (int i = 0; i < AMOUNT; i++)
        test_print(&data[i], i, test_file, &test_count, &correct_test_count);

    printf("RESULT\tcorrect tests:\t%d\n"
           "\ttotal:\t\t%d\n\n",
           test_count, correct_test_count);

    printf("<test_end>\n\n");
}
