#include <stdio.h>
#include <math.h>
#include "test.hpp"
#include "squaresolver.hpp"

void test( struct TEST_DATA *test, int num, FILE *f )
{
    double x1 = START_VAL, x2 = START_VAL;
    test_reader(test, f);

    printf("%d)", num + 1);

    if (errno == INC_INP)
    {
        char sym = '0';
        while ((sym = getc(f)) != '\n')
            ;

        int res = errno;

        printf("\tinput:\n\tincorrect input\n\n"
            "\toutput:\n\tres:\t%d\n\tx1:\t%lf\n\tx2:\t%lf\n\n\n\n",
            res, x1, x2);
    }
    else
    {
        int res = squaresolver(test->a, test->b, test->c, &x1, &x2);
        printf("\tinput:\n\ta:\t%lf\n\tb:\t%lf\n\tc:\t%lf\n\n"
            "\toutput:\n\tres:\t%d\n\tx1:\t%lf\n\tx2:\t%lf\n\n"
            "\twanted:\n\tans:\t%s\n\tx1:\t%lf\n\tx2:\t%lf\n\n\n\n",
            test->a, test->b, test->c,
            res, x1, x2,
            test->res, test->x1, test->x2);
    }

    errno = OK;
}

void test_reader( struct TEST_DATA *test, FILE *f )
{
    if (!fscanf(f, "%lf %lf %lf %lf %lf %s", &(test->a), &(test->b), &(test->c),
        &(test->x1), &(test->x2), &(test->res)) ||
        !finite(test->a) || !finite(test->b) || !finite(test->c))
        errno = INC_INP;

    char tail = getc(f);
    if (tail != '\n')
        errno = INC_INP;
}
