#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "solver.hpp"
#include "interface.hpp"

Errors read_valid_double( double *a )
{
    assert(a != NULL);

    if (!scanf("%lf", a) || !finite(*a))
        return INCORRECT_INPUT;

    char tail = getchar();
    if (tail != '\n')
        return INCORRECT_INPUT;

    return NO_ERROR;
}

Input_status input_coefficients( double *a, double *b, double *c )
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    return (Input_status)(read_coefficient(a, 'a') && read_coefficient(b, 'b') && read_coefficient(c, 'c'));
}

Input_status read_coefficient( double *a, char coef )
{
    assert(a != NULL);

    printf("%c = ", coef);

    int read_status = read_valid_double(a);
    if (read_status != NO_ERROR)
    {
        error_printer(read_status);

        return FAILED;
    }

    return SUCCESSFUL;
}

void print_solution( int res, double x1, double x2 )
{
    assert(finite(res));
    assert(finite(x1));
    assert(finite(x2));

    switch(res)
    {
        case TWO_ROOTS:
            printf("%lf, %lf\n", x1, x2);
            break;

        case ONE_ROOT:
            if (is_zero(x1))
                x1 = 0;
            printf("%lf\n", x1);
            break;

        case INF_ROOTS:
            printf("any number\n");
            break;

        case NO_ROOTS:
            printf("nothing\n");
            break;

        default:
            assert(false && "unexpected number of roots");
            break;
    }
}

void skip_line( FILE *f )
{
    assert(f != NULL);

    char sym = '\0';

    do
    {
        sym = getc(f);
    }
    while (sym != '\n' && sym != EOF);
}

void interactive_quadratic_solver()
{
    printf("=============================\n");
    printf("equation: a*x^2 + b*x + c = 0\n");

    double a = 0;
    double b = 0;
    double c = 0;

    if (input_coefficients(&a, &b, &c) == FAILED)
        return;

    double x1 = 0;
    double x2 = 0;
    double res = square_solver(a, b, c, &x1, &x2);

    printf("ans: ");
    print_solution(res, x1, x2);
    printf("\n");
}
