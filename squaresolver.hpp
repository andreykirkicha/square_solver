/*!
    This list is used to return description of the result in case of successful
    completion of the solving program.
*/
enum ROOTS {
    INF_ROOTS   = 0, ///< equation has got infinite number of roots
    ONE_ROOT    = 1, ///< equation has got one root
    TWO_ROOTS   = 2, ///< equation has got two roots
    NO_ROOTS    = 3  ///< equation hasn't got any roots
};

/*!
    This list is used to indicate errors by numbers.
*/
enum ERRORS {
    OK              =  0, ///< no errors
    INCORRECT_INPUT = -1, ///< some pointer is NULL
};

/*!
    This list is used to define session status.
*/
enum SESSION {
    END,
    CONTINUE
};

/*!
    This list is used to define input correctness.
*/
enum INPUT_STATUS {
    FAILED,
    SUCCESSFUL
};

const double EPS = 2e-6; ///< Accurancy for comparison of double value and zero

/*!
    This function is used to simplify working of read_coefficient function. It gets
    a double value and check if it's valid.
    \param[in] a - a value from a user
    \return OK (0) - it was successfully completed
    \throw INCORRECT_INPUT (-1) - incorrect input
*/
ERRORS read_valid_double( double *a );

/*!
    This function is used to get equation coefficients from stdin.\
    Equation: a*x^2 + b*x + c = 0.
    \param[in] a - value of coefficient a
    \param[in] b - value of coefficient b
    \param[in] c - value of coefficient c
    \return SUCCESSFUL  - it was successfully completed
    \return FAILED - there's some errors
*/
INPUT_STATUS input_coefficients( double *a, double *b, double *c );

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
    \return ONE_ROOT  (1) - equation has got one root
    \return INF_ROOTS (0) - equation has got infinite number of roots
*/
ROOTS square_solver( double a, double b, double c, double *x1, double *x2 );

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
ROOTS linear_solver( double b, double c, double *x1 );

/*!
    This function puts the result on a screen depending on return values.
    \param[in] res - result number
    \param[in] x1  - first root of the equation (if exists)
    \param[in] x2  - second root of the equation (if exists)
*/
void print_solution( int res, double x1, double x2 );

/*!
    This function informs user about errors that occured and begins process again.
    \param[in] error - number of the error
*/
void error_printer( int error );

/*!
    This function compares a double value with zero.
    \param[in] a   - double value
    \param[in] lim - accuracy (EPS by default)
    \return 1 - a == 0
    \return 0 - a != 0
*/
int is_zero( double a, double lim = EPS );

/*!
    This function clears line in buffer after incorrect input.
    \param[in] f - input stream
*/
void skip_line( FILE *f );

/*!
    This function defines what user wants to do: quit, begin test or solve quadratic equation.
    \param[in] file_name - name of test file that user will use in case of pressing 't'
    \param[out] session  - current status of session
*/
void ask_question( const char *file_name, bool *session );

/*!
    This function is used to print results of test.
    \param[in] test_file_name - name of test file
*/
void test( const char *file_name );

/*!
    This function provides user input, solving quadratic equation and printing solution.
*/
void interactive_quadratic_solver();

/*!
    This function is used to get test data from .txt file.
    \param[in] f     - test .txt file
    \param[out] test - structure that is used to contain test data
    \return OK (0)               - correct input data
    \return INCORRECT_INPUT (-1) - incorrect input data
*/
ERRORS test_read( struct Test_data *test, FILE *f );

/*!
    This function solves quadratic equation using coefficients from test file if input is correct,
    otherwise returns error number.
    \param[in] test - structure that is used to contain test data
    \param[in] num  - number of test
    \param[in] f    - test file
    \return OK (0) - input was correct
    \return INCORRECT_INPUT (-1) - input was incorrect
*/
ERRORS test_calculate( struct Test_data *test, int num, FILE *f );

/*!
    This function gets value for one coefficient from user.
    \param[in] a    - value of coefficient
    \param[in] coef - letter designation of coefficient
*/
INPUT_STATUS read_coefficient( double *a, char coef );
