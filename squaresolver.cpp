#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXLEN 10

int isnum(char *str, int len);

int main()
{
    //double a, b, c, D;
    double D, a, b, c;
    char x[MAXLEN], y[MAXLEN], z[MAXLEN];

    while (1)
    {
        printf("-----------------------------\n");
        printf("equation: a*x^2 + b*x + c = 0\n");
        printf("a = ");
        scanf("%s", x);
        if (isnum(x, MAXLEN) == -1)
        {
            printf("<error>: %s is not a number\n", x);
            continue;
        }
        if (isnum(x, MAXLEN) == -2)
        {
            printf("<error>: %s is too big\n", x);
            continue;
        }
        printf("b = ");
        scanf("%s", y);
        if (isnum(y, MAXLEN) == -1)
        {
            printf("<error>: %s is not a number\n", y);
            continue;
        }
        if (isnum(y, MAXLEN) == -2)
        {
            printf("<error>: %s is too big\n", y);
            continue;
        }
        printf("c = ");
        scanf("%s", z);
        if (isnum(z, MAXLEN) == -1)
        {
            printf("<error>: %s is not a number\n", z);
            continue;
        }
        if (isnum(z, MAXLEN) == -2)
        {
            printf("<error>: %s is too big\n", z);
            continue;
        }

        a = atof(x);
        b = atof(y);
        c = atof(z);

        printf("ans: ");

        if (a == 0)
        {
            if (b == 0)
            {
                if (c == 0)
                    printf("any number\n");
                else
                    printf("nothing\n");
            }
            else
                printf("%lf\n", - c / b);
        }
        else
        {
            D = b * b - 4 * a * c;
            if (D > 0)
                printf("%lf, %lf\n", (-b + sqrt(D)) / (2 * a), (-b - sqrt(D)) / (2 * a));
            else if (D == 0)
                printf("%lf\n", (-b + sqrt(D)) / (2 * a));
            else
                printf("nothing\n");
        }
    }
    return 0;
}

int isnum(char *str, int len)
{
    int i = 0;

    while (isdigit(str[i]))
    {
        i++;
        if (i > len)
            return -2;
    }

    if (str[i] == '\0')
        return i;
    else
        return -1;
}
