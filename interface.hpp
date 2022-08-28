#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "solver.hpp"
#include "error.hpp"

/*!
    This list is used to define input correctness.
*/
enum Input_status {
    FAILED,
    SUCCESSFUL
};

/*!
    This function is used to simplify working of read_coefficient function. It gets
    a double value and check if it's valid.
    \param[in] a - a value from a user
    \return NO_ERROR (0) - it was successfully completed
    \throw INCORRECT_INPUT (-1) - incorrect input
*/
Errors read_valid_double( double *a );

/*!
    This function is used to get equation coefficients from stdin.\
    Equation: a*x^2 + b*x + c = 0.
    \param[in] a - value of coefficient a
    \param[in] b - value of coefficient b
    \param[in] c - value of coefficient c
    \return SUCCESSFUL  - it was successfully completed
    \return FAILED - there's some Errors
*/
Input_status input_coefficients( double *a, double *b, double *c );

/*!
    This function gets value for one coefficient from user.
    \param[in] a    - value of coefficient
    \param[in] coef - letter designation of coefficient
*/
Input_status read_coefficient( double *a, char coef );

/*!
    This function clears line in buffer after incorrect input.
    \param[in] f - input stream
*/
void skip_line( FILE *f );

/*!
    This function puts the result on a screen depending on return values.
    \param[in] res - result number
    \param[in] x1  - first root of the equation (if exists)
    \param[in] x2  - second root of the equation (if exists)
*/
void print_solution( int res, double x1, double x2 );

/*!
    This function provides user input, solving quadratic equation and printing solution.
*/
void interactive_quadratic_solver();

#endif
