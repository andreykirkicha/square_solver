#include <stdio.h>
#include <math.h>
#include <string.h>
#include "test.hpp"
#include "squaresolver.hpp"

ERRORS test_calculate( struct TEST_DATA *test, int num, FILE *f )
{
    // TODO: START_VAL is very weird solution to pretty much non-existent problem,
    //       please, write conventional code (e.g. initialize with zeros) and don't
    //       check values of other roots if there isn't that many (e.g. don't check
    //       second root if solve_quadratic returned ONE_ROOT) it complicates things
    //       much more than it helps since no one will ever use other roots anyway.
    double x1 = START_VAL, x2 = START_VAL;

    test_init(test);
    ERRORS error = test_reader(test, f);

    printf("%d)", num + 1);

    if (error == INC_INP)
    {
        clear_buf(f);
        int res = error;

        printf("\tinput:\n"
               "\tincorrect input\n\n"  // TODO: please, make this readable
               "\toutput:\n\tres:\t%d\n\tx1:\t%lf\n\tx2:\t%lf\n\n",
            res, x1, x2);
    }

    else
    {
        int res = square_solver(test->a, test->b, test->c, &x1, &x2);

        // TODO: please, make this readable
        printf("\tinput:\n\ta:\t%lf\n\tb:\t%lf\n\tc:\t%lf\n\n"
            "\toutput:\n\tres:\t%d\n\tx1:\t%lf\n\tx2:\t%lf\n\n"
            "\twanted:\n\tans:\t%s\n\tx1:\t%lf\n\tx2:\t%lf\n\n",
            test->a, test->b, test->c,
            res, x1, x2,
            test->res, test->x1, test->x2);
    }

    error = OK;

    return error;
}

// TODO: how do you like read_test instead of test_reader?
// test_reader implies object and state, but this function
// is actually pretty "pure" if you can say so, it does one
// thing and doesn't store any state, i think name should
// reflect that!
ERRORS test_reader( struct TEST_DATA *test, FILE *f )
{
    // TODO: record fscanf's return value in variable (to simplify this huge condition), also check for
    //       all matches instead of one fscanf(...) != number, but comment where number comes from!
    if (!fscanf(f, "%lf %lf %lf %lf %lf %s", &(test->a), &(test->b), &(test->c),
        &(test->x1), &(test->x2), test->res) ||
        !finite(test->a) || !finite(test->b) || !finite(test->c))
        return INC_INP;

    char tail = getc(f);

    if (tail != '\n')
        return INC_INP;

    return OK;
}

void test_init( struct TEST_DATA *test )
{
    test->a = START_VAL;   // TODO: This is just *test = {} if you replace START_VAL with zero
    test->b = START_VAL;   // TODO: Read about named designators, see if you can apply them here
    test->c = START_VAL;
    test->x1 = START_VAL;
    test->x2 = START_VAL;
    strcpy(test->res, ""); // test->res[0] = '\0';  which is still zero and would work with {}
    // If you want this to be safer you should ^ write '\0' in every element of buffer instead
    // of just this one (memset)
}
