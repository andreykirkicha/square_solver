#ifndef SOLVER_HPP
#define SOLVER_HPP

/*!
    This list is used to return description of the result in case of successful
    completion of the solving program.
*/
enum Roots {
    INF_ROOTS, ///< equation has got infinite number of Roots
    ONE_ROOT,  ///< equation has got one root
    TWO_ROOTS, ///< equation has got two Roots
    NO_ROOTS   ///< equation hasn't got any Roots
};

const double EPS = 2e-6; ///< Accurancy for comparison of two double values

/*!
    This function is used to solve the quadratic equation.\
    Equation: a*x^2 + b*x + c = 0.
    \param[in] a  - coefficient a
    \param[in] b  - coefficient b
    \param[in] c  - coefficient c
    \param[out] x1 - pointer to first root of the equation (if exists)
    \param[out] x2 - pointer to second root of the equation (if exists)
    \return NO_ROOTS  (3) - equation hasn't got any roots
    \return TWO_ROOTS (2) - equation has got two roots
    \return ONE_ROOTS (1) - equation has got one root
    \return INF_ROOTS (0) - equation has got infinite number of roots
*/
Roots square_solver( double a, double b, double c, double *x1, double *x2 );

/*!
    This function is used to solve the linear equation (to simplify working
    of squaresolver).\
    Equation: b*x + c = 0.
    \param[in] b - coefficient b
    \param[in] c - coefficient c
    \param[out] x1 - pointer to root of the equation (if exists)
    \return NO_ROOTS  (3) - equation hasn't got any roots
    \return ONE_ROOT  (1) - equation has got one root
    \return INF_ROOTS (0) - equation has got infinite number of roots
*/
Roots linear_solver( double b, double c, double *x1 );

/*!
    This function compares a double value with zero.
    \param[in] a - double value
    \param[in] lim - accuracy (EPS by default)
    \return 1 - a == 0
    \return 0 - a != 0
*/
int is_zero( double a, double lim = EPS );

/*!
    This function compares two double values.
    \param[in] a - first double value
    \param[in] b - second double value
    \return 1 - a == b
    \return 0 - a != b
*/
int is_equal( double a, double b, double lim = EPS );

#endif
