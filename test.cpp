#include <stdio.h>
#include "test.hpp"
#include "squaresolver.h"

void test(struct IN in_str[], struct OUT out_str[], struct ANS ans_str[], int amount)
{
    int i = 0;

    for ( ; i < amount; i++)
    {
        printf("%d)", i + 1);
        out_str[i].res = squaresolver(in_str[i].a, in_str[i].b, in_str[i].c, &out_str[i].x1, &out_str[i].x2);
        printf("\tinput:\n\ta:\t%lf\n\tb:\t%lf\n\tc:\t%lf\n\n"
            "\toutput:\n\tres:\t%lf\n\tx1:\t%lf\n\tx2:\t%lf\n\n"
            "\treal situation:\n\tans:\t%s\n\tx1:\t%lf\n\tx2:\t%lf\n\n\n",
            in_str[i].a, in_str[i].b, in_str[i].c,
            out_str[i].res, out_str[i].x1, out_str[i].x2,
            ans_str[i].ans, ans_str[i].x1, ans_str[i].x2);
    }
}
