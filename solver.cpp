#include <math.h>
#include <stdio.h>
#include <assert.h>

#include "solver.hpp"

Roots square_solver( double a, double b, double c, double *x1, double *x2 )
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(finite(a));
    assert(finite(b));
    assert(finite(c));

    if (is_zero(a))
        return linear_solver(b, c, x1);

    if (is_zero(c) && !is_zero(b))
    {
        linear_solver(a, b, x1);
        *x2 = 0;

        return TWO_ROOTS;
    }

    double discriminant = b * b - 4 * a * c;

    if (is_zero(discriminant))
    {
        *x1 = -b / (2 * a);

        return ONE_ROOT;
    }

    if (discriminant > 0)
    {
        double sqrt_discriminant = sqrt(discriminant);

        *x1 = (-b - sqrt_discriminant) / (2 * a);
        *x2 = (-b + sqrt_discriminant) / (2 * a);

        return TWO_ROOTS;
    }

    return NO_ROOTS;
}

Roots linear_solver( double b, double c, double *x1 )
{
    assert(x1 != NULL);
    assert(finite(b));
    assert(finite(c));

    if (is_zero(b))
        return (is_zero(c)) ? INF_ROOTS : NO_ROOTS;

    *x1 = -c / b;

    return ONE_ROOT;
}

int is_zero( double a, double lim )
{
    assert(finite(a));
    assert(finite(lim));

    return (fabs(a) < lim);
}

int is_equal( double a, double b, double lim )
{
    assert(finite(a));
    assert(finite(b));
    assert(finite(lim));

    return (fabs(a - b) < lim);
}
