#include <stdio.h>
#include <math.h>
#include "test.hpp"
#include "squaresolver.hpp"

ERRORS test_calculate( struct Test_data *test, int num, FILE *f )
{
    double x1 = 0;
    double x2 = 0;

    ERRORS error = test_read(test, f);

    printf("%d)", num + 1);

    if (error == INCORRECT_INPUT)
    {
        skip_line(f);
        int res = error;

        printf("\tinput:\n"
               "\tincorrect input\n\n"
               "\toutput:\n"
               "\tres:\t%d\n\n",
               res);
    }

    else
    {
        int res = square_solver(test->a, test->b, test->c, &x1, &x2);

        switch(res)
        {
            case INF_ROOTS:
            case NO_ROOTS:
               printf("\tinput:\n"
                      "\ta:\t%lf\n"
                      "\tb:\t%lf\n"
                      "\tc:\t%lf\n\n"
                      "\toutput:\n"
                      "\tres:\t%d\n\n"
                      "\twanted:\n"
                      "\tans:\t%s\n\n",
                      test->a, test->b, test->c,
                      res,
                      test->res);
               break;
            case ONE_ROOT:
               printf("\tinput:\n"
                      "\ta:\t%lf\n"
                      "\tb:\t%lf\n"
                      "\tc:\t%lf\n\n"
                      "\toutput:\n"
                      "\tres:\t%d\n"
                      "\tx1:\t%lf\n\n"
                      "\twanted:\n"
                      "\tans:\t%s\n"
                      "\tx1:\t%lf\n\n",
                      test->a, test->b, test->c,
                      res, x1,
                      test->res, test->x1);
               break;
            case TWO_ROOTS:
               printf("\tinput:\n"
                      "\ta:\t%lf\n"
                      "\tb:\t%lf\n"
                      "\tc:\t%lf\n\n"
                      "\toutput:\n"
                      "\tres:\t%d\n"
                      "\tx1:\t%lf\n"
                      "\tx2:\t%lf\n\n"
                      "\twanted:\n"
                      "\tans:\t%s\n"
                      "\tx1:\t%lf\n"
                      "\tx2:\t%lf\n\n",
                      test->a, test->b, test->c,
                      res, x1, x2,
                      test->res, test->x1, test->x2);
              break;
        }
    }

    return error;
}

ERRORS test_read( struct Test_data *test, FILE *f )
{
    if (fscanf(f, "%lf %lf %lf %lf %lf %s", &(test->a), &(test->b), &(test->c),
        &(test->x1), &(test->x2), test->res) != ARGUMENTS_NUMBER ||
        !finite(test->a) || !finite(test->b) || !finite(test->c))
        return INCORRECT_INPUT;

    char tail = getc(f);

    if (tail != '\n')
        return INCORRECT_INPUT;

    return OK;
}

