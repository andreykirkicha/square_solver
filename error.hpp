#ifndef ERROR_HPP
#define ERROR_HPP

/*!
    This list is used to indicate errors by numbers.
*/
enum Errors {
    NO_ERROR = 0, ///< there isn't any errors
    INCORRECT_INPUT = -1, ///< incorrect input
};

/*!
    This function informs user about errors that occured and begins process again.
    \param[in] error - number of the error
*/
void error_printer( int error );

#endif
