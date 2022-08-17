#include <stdio.h>

int reader(double *a)
{
    if (!scanf("%lf", a))
    {
        printf("<error> not a number\n");
        while (getchar() != '\n')
            ;
        return -1;
    }
    return 0;
}

int input_coefficient(double *a, double *b, double *c)
{
    printf("a = ");
    if (reader(a) == -1)
        return -1;
    printf("b = ");
    if (reader(b) == -1)
        return -1;
    printf("c = ");
    if (reader(c) == -1)
        return -1;
    return 0;
}
