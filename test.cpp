#include <stdio.h>
#include "test.hpp"
#include "squaresolver.h"

void test(struct IN in_str[], struct OUT out_str[], int amount)
{
    int i = 0;

    for ( ; i < amount; i++)
    {
        printf("%d)", i + 1);
        out_str[i].res = squaresolver(in_str[i].a, in_str[i].b, in_str[i].c, &out_str[i].x1, &out_str[i].x2);
        if (out_str[i].res == TWO_ROOTS)
            printf("\ta:\t%lf\n\tb:\t%lf\n\tc:\t%lf\n\tres:\t%s\n\tx1:\t%lf\n\tx2:\t%lf\n\n",
            in_str[i].a, in_str[i].b, in_str[i].c, "two roots", out_str[i].x1, out_str[i].x2);
        if (out_str[i].res == ONE_ROOT)
            printf("\ta:\t%lf\n\tb:\t%lf\n\tc:\t%lf\n\tres:\t%s\n\tx:\t%lf\n\n",
            in_str[i].a, in_str[i].b, in_str[i].c, "one root", out_str[i].x1);
        if (out_str[i].res == INF_ROOTS)
            printf("\ta:\t%lf\n\tb:\t%lf\n\tc:\t%lf\n\tres:\t%s\n\n",
            in_str[i].a, in_str[i].b, in_str[i].c, "any number");
        if (out_str[i].res == NO_ROOTS)
            printf("\ta:\t%lf\n\tb:\t%lf\n\tc:\t%lf\n\tres:\t%s\n\n",
            in_str[i].a, in_str[i].b, in_str[i].c, "no roots");
    }
}
