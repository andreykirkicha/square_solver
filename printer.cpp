#include <stdio.h>

void printer(int res, double *x1, double *x2, char *str)
{
    printf("ans: ");
    if (res == 2)
        printf("%lf, %lf\n", *x1, *x2);
    else if (res == 1)
        printf("%lf\n", *x1);
    else
        printf("%s\n", str);
}
