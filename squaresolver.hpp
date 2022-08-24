#include <errno.h>
/*!
    This list is used to return description of the result in case of successful completion of the solving program.
*/
enum roots {
    INF_ROOTS   = 0, ///< equation has got infinite number of roots
    ONE_ROOT    = 1, ///< equation has got one root
    TWO_ROOTS   = 2, ///< equation has got two roots
    NO_ROOTS    = 3  ///< equation hasn't got any roots
};
/*!
    This list is used to indicate errors by numbers.
*/
enum errors {
    OK      =  0, ///< no errors
    INC_INP = -1, ///< incorrect input
    PTR_NUL = -2, ///< some pointer has got value NULL
    CNT_OP  = -3  ///< can't open the file
};
const double EPS = 0.000002; ///< Accuracy that is used to compare double values.

/*!
    This function is used to simplify working of input_coefficient function. It gets value for one coefficient
    from stdin.
    \param[in] a - variable that gets a value from a user
    \return OK (0) - it was successfully completed
    \throw PTR_NUL (-2) - there's not memory to declare the variable
    \throw INC_INP (-1) - incorrect input
*/
int reader( double *a );
/*!
    This function is used to get equation coefficients from stdin.\
    Equation: a*x^2 + b*x + c = 0.
    \param[in] a - variable that gets value of coefficient a
    \param[in] b - variable that gets value of coefficient b
    \param[in] c - variable that gets value of coefficient c
    \return 0  - it was successfully completed
    \return -1 - there's some errors
*/
int input_coefficient( double *a, double *b, double *c );
/*!
    This function is used to solve the quadratic equation.\
    Equation: a*x^2 + b*x + c = 0.
    \param[in] a  - coefficient a
    \param[in] b  - coefficient b
    \param[in] c  - coefficient c
    \param[out] x1 - variable to contain first root of the equation (if exists)
    \param[out] x2 - variable to contain second root of the equation (if exists)
    \return NO_ROOTS  (3) - equation hasn't got any roots
    \return TWO_ROOTS (2) - equation has got two roots
    \return ONE_ROOT  (1) - equation has got one root
    \return INF_ROOTS (0) - equation has got infinite number of roots
    \throw PTR_NUL (-2) - some pointer has got value NULL
*/
int squaresolver( double a, double b, double c, double *x1, double *x2 );
/*!
    This function is used to solve the linear equation (to simplify working
    of squaresolver).\
    Equation: b*x + c = 0.
    \param[in] b - coefficient b
    \param[in] c - coefficient c
    \param[out] x1 - variable to contain the root of the equation (if exists)
    \return NO_ROOTS  (3) - equation hasn't got any roots
    \return ONE_ROOT  (1) - equation has got one root
    \return INF_ROOTS (0) - equation has got infinite number of roots
    \throw PTR_NUL (-2) - some pointer has got value NULL
*/
int linsolver( double b, double c, double *x1 );
/*!
    This function puts the result on a screen depending on return values.
    \param[in] res - result/error number
    \param[in] x1  - first root of the equation (if exists)
    \param[in] x2  - second root of the equation (if exists)
*/
void printer( int res, double x1, double x2 );
/*!
    This function informs user about errors that occured and begins process again.
    \param[in] error - number of the error
*/
void error_handler( int error );
/*!
    This function compares two double values with given accuracy.
    \param[in] a   - first value
    \param[in] b   - second value
    \param[in] lim - accuracy
    \return 1 - a == b
    \return 0 - a != b
*/
int is_equal( double a, double b, double lim );
/*!
    This function clears buffer after incorrect input.
    \param[in] f - input stream
*/
void clear_buf( FILE *f );
