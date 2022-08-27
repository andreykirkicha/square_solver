const int AMOUNT    =  10;  ///< Amount of tests
const int ANS_LEN   =  16;  ///< Max length of answer

/*!
    This structure is used to give access to user's input data for test functions.
*/
struct Test_data {
    double a;           ///< Coefficient a
    double b;           ///< Coefficient b
    double c;           ///< Coefficient c
    double x1;          ///< First root (if exists)
    double x2;          ///< Second root (if exists)
    char res[ANS_LEN];  ///< Description of the result
};

const int ARGUMENTS_NUMBER = 6; ///< number of arguments in every string of test file
