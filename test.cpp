#include <stdio.h>
#include <math.h>
#include "test.hpp"
#include "squaresolver.h"

void test(struct IN in_str[], struct OUT out_str[], struct ANS ans_str[], int amount, int err_num, FILE *f)
{
    int i = 0;

    for ( ; i < amount; i++)
    {
        if (!fscanf(f, "%lf %lf %lf", &(in_str[i].a), &(in_str[i].b), &(in_str[i].c)) ||
            !finite(in_str[i].a) || !finite(in_str[i].b) || !finite(in_str[i].c))
            err_num = INC_INP;

        char tail = getc(f);
        if (tail != '\n')
            err_num = INC_INP;

        printf("%d)", i + 1);

        if (err_num == INC_INP)
        {
            char sym = '0';
            while ((sym = getc(f)) != '\n')
                ;

            out_str[i].res = err_num;

            printf("\tinput:\n\tincorrect input\n\n"
                "\toutput:\n\tres:\t%lf\n\tx1:\t%lf\n\tx2:\t%lf\n\n"
                "\twanted:\n\tans:\t%s\n\tx1:\t%lf\n\tx2:\t%lf\n\n\n\n",
                out_str[i].res, out_str[i].x1, out_str[i].x2,
                ans_str[i].ans, ans_str[i].x1, ans_str[i].x2);
        }
        else
        {
            out_str[i].res = squaresolver(in_str[i].a, in_str[i].b, in_str[i].c, &out_str[i].x1, &out_str[i].x2);
            printf("\tinput:\n\ta:\t%lf\n\tb:\t%lf\n\tc:\t%lf\n\n"
                "\toutput:\n\tres:\t%lf\n\tx1:\t%lf\n\tx2:\t%lf\n\n"
                "\twanted:\n\tans:\t%s\n\tx1:\t%lf\n\tx2:\t%lf\n\n\n\n",
                in_str[i].a, in_str[i].b, in_str[i].c,
                out_str[i].res, out_str[i].x1, out_str[i].x2,
                ans_str[i].ans, ans_str[i].x1, ans_str[i].x2);
        }

        err_num = OK;
    }
}
