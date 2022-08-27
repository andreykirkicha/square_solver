// TODO: use include guards or pragma once to prevent double inclusion

/*!
    This list is used to return description of the result in case of successful completion of the solving program.
*/
enum ROOTS {
    INF_ROOTS   = 0, ///< equation has got infinite number of roots
    ONE_ROOT    = 1, ///< equation has got one root
    TWO_ROOTS   = 2, ///< equation has got two roots
    NO_ROOTS    = 3  ///< equation hasn't got any roots
};

// TODO: split this file in many headers
// TODO: make sure that core functionality is contained within one separate header file
//       and easy to use for potential library user.
/*!
    This list is used to indicate errors by numbers.
*/
enum ERRORS {
    OK      =  0, ///< no errors
    // TODO: better naming, for example, INCORRECT_INPUT
    INC_INP = -1, ///< some pointer is NULL
    CNT_OP  = -2  ///< can't open the file
};

enum SESSION {
    END,
    CONTINUE
};

enum INPUT_STATUS {
    FAILED,
    SUCCESSFUL
};

const double EPS = 2e-6;
/*!
    This function is used to simplify working of input_coefficient function. It gets value for one coefficient
    from stdin.
    \param[in] a - variable that gets a value from a user
    \return OK (0) - it was successfully completed
    \throw PTR_NUL (-2) - there's not memory to declare the variable
    \throw INC_INP (-1) - incorrect input
*/
ERRORS reader( double *a );
/*!
    This function is used to get equation coefficients from stdin.\
    Equation: a*x^2 + b*x + c = 0.
    \param[in] a - variable that gets value of coefficient a
    \param[in] b - variable that gets value of coefficient b
    \param[in] c - variable that gets value of coefficient c
    \return 0  - it was successfully completed
    \return -1 - there's some errors
*/
INPUT_STATUS input_coefficients( double *a, double *b, double *c );
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
ROOTS square_solver( double a, double b, double c, double *x1, double *x2 );
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
ROOTS linear_solver( double b, double c, double *x1 );
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
void error_printer( int error );
/*!
    This function compares two double values.
    \param[in] a   - first value
    \param[in] b   - second value
    \return 1 - a == b
    \return 0 - a != b
*/
int is_equal( double a, double b, double lim = EPS );
/*!
    This function clears buffer after incorrect input.
    \param[in] f - input stream
*/
void clear_buf( FILE *f );
void ask_question( char *argv[], bool *session );
void test( char *argv[] );
void input_calculate_output();
ERRORS test_reader( struct TEST_DATA *test, FILE *f );
ERRORS test_calculate( struct TEST_DATA *test, int num, FILE *f );
