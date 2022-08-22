#include <stdio.h>
#include <math.h>
#include "test.hpp"
#include "squaresolver.hpp"

void test(struct TEST_DATA *test[], int amount, FILE *f)
{
    double x1 = START_VAL, x2 = START_VAL;
    int i = 0;

    printf("<test_begin>\n\n");

    for ( ; i < amount; i++)
    {
        printf("%d)", i + 1);
        test_reader(test[i], f);

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
            int res = squaresolver(test[i]->a, test[i]->b, test[i]->c, &(test[i]->x1), &(test[i]->x2));
            printf("\tinput:\n\ta:\t%lf\n\tb:\t%lf\n\tc:\t%lf\n\n"
                "\toutput:\n\tres:\t%d\n\tx1:\t%lf\n\tx2:\t%lf\n\n"
                "\twanted:\n\tans:\t%s\n\tx1:\t%lf\n\tx2:\t%lf\n\n\n\n",
                test[i]->a, test[i]->b, test[i]->c,
                res, x1, x2,
                test[i]->res, test[i]->x1, test[i]->x2);
        }
        errno = OK;
    }

    printf("<test_end>\n\n");
}

void test_reader(struct TEST_DATA *test, FILE *f)
{
    if (!fscanf(f, "%lf %lf %lf %lf %lf %s", &(test->a), &(test->b), &(test->c),
        &(test->x1), &(test->x2), &(test->res)) ||
        !finite(test->a) || !finite(test->b) || !finite(test->c))
        errno = INC_INP;

    char tail = getc(f);
    if (tail != '\n')
        errno = INC_INP;
}
