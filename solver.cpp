#include <math.h>
#include <stdio.h>
#include <assert.h>
#include "squaresolver.hpp"

ROOTS square_solver( double a, double b, double c, double *x1, double *x2 )
{
    assert(x1 != NULL && x2 != NULL && finite(a) && finite(b) && finite(c));

    if (is_equal(a, 0)) // TODO: is_zero? :)
        return linear_solver(b, c, x1);

    if (is_equal(c, 0) && !is_equal(b, 0)) // TODO: is_zero? :)
    {
        linear_solver(a, b, x1);
        *x2 = 0;

        return TWO_ROOTS;
    }

    // TODO: please, use same naming style across all project
    //       this is the only local variable i've ever seen here that
    //       starts with a capital letter, fix it!
    double Discriminant = b * b - 4 * a * c;

    if (Discriminant > EPS)
    {
        double sqrtDiscriminant = sqrt(Discriminant);

        *x1 = (-b - sqrtDiscriminant) / (2 * a);
        *x2 = (-b + sqrtDiscriminant) / (2 * a);

        return TWO_ROOTS;
    }

    if (is_equal(Discriminant, 0)) // TODO: Am I imagining or is this is_zero too?)
    {
        *x1 = -b / (2 * a);

        return ONE_ROOT;
    }

    return NO_ROOTS;
}

ROOTS linear_solver( double b, double c, double *x1 )
{
    assert(x1 != NULL && finite(b) && finite(c));

    if (is_equal(b, 0))  // TODO: :)
        return (is_equal(c, 0)) ? INF_ROOTS : NO_ROOTS;

    *x1 = -c / b;

    return ONE_ROOT;
}

int is_equal( double a, double b, double lim )
{
    assert(finite(a) && finite(b));

    return (fabs(a - b) < lim);
}
