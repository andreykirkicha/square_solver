const int AMOUNT    =  10;  ///< Amount of tests
const int ANS_LEN   =  16;  ///< Max length of answer
const int START_VAL = -27;  ///< Default value of TEST_DATA fields
/*!
    This structure is used to give access to user's input data for test functions.
*/
struct TEST_DATA {
    double a;           ///< Coefficient a
    double b;           ///< Coefficient b
    double c;           ///< Coefficient c
    double x1;          ///< First root (if exists)
    double x2;          ///< Second root (if exists)
    char res[ANS_LEN];  ///< Description of the result
};

/*!
    This function is used to display input data, output of the program and expectation of an user.
    \param[in] test - element of array of TEST_DATA structures that contains user's input and expected output.
    \param[in] num - number of the element.
    \param[in] f - .txt file for user to fill with input data and expected output:
    coefficients of equation a*x^2 + b*x + c = 0 (a, b, c),
    roots of this equation (x1, x2) and description of the result (res).
*/
void test( struct TEST_DATA *test, int num, FILE *f );
/*!
    This function is used to copy user's test data from .txt file to TEST_DATA structure.
    \param[in] test - element of array of TEST_DATA structures that contains user's input and expected output.
    \param[in] f - .txt file for user to fill with input data and expected output:
    coefficients of equation a*x^2 + b*x + c = 0 (a, b, c),
    roots of this equation (x1, x2) and description of the result (res).
*/
void test_reader( struct TEST_DATA *test, FILE *f );
/*!
    This function is used to fill TEST_DATA structure with default values.
    \param[in] test - element of array of TEST_DATA structures that contains user's input and expected output.
*/
void test_init( struct TEST_DATA *test );
