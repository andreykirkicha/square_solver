#ifndef QUESTION_HPP
#define QUESTION_HPP

/*!
    This function provides user to interact with functions of the program.
    \param[in] file_name - name of test file that user would use
    \param[out] session_continue - variable that controls status of session
*/
void request( const char *file_name, bool *session_continue );

/*!
    This function breaks iteration of session skiping line until '\n' or EOF and begins another iteration;
*/
void end_of_iteration();

#endif
