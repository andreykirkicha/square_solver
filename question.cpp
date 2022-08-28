#if SYSTEM == WINDOWS
#include <conio.h>
#endif

#include <stdio.h>
#include <assert.h>

#include "test.hpp"
#include "question.hpp"
#include "interface.hpp"

#if SYSTEM == WINDOWS

void request( const char *file_name, bool *session_continue )
{
    assert(file_name != NULL);
    assert(session_continue != NULL);

    printf("press 'q' to quit, 't' to begin test or other key to start solving\n");

    char option = _getch();

    switch(option)
    {
        case 'q':
            *session_continue = false;
            break;

        case 't':
            test(file_name);
            break;

        default:
            interactive_quadratic_solver();
            break;
    }
}

#else

void request( const char *file_name, bool *session_continue )
{
    assert(file_name != NULL);
    assert(session_continue != NULL);

    printf("press 'q' to quit, 't' to begin test or enter to start solving\n");

    char option = getchar();

    switch(option)
    {
        case 'q':
            if (getchar() != '\n')
            {
                end_of_iteration();
                break;
            }
            *session_continue = false;
            break;

        case 't':
            test(file_name);
            skip_line(stdin);
            break;

        case '\n':
            interactive_quadratic_solver();
            break;

        default:
            end_of_iteration();
            break;
    }
}

void end_of_iteration()
{
    skip_line(stdin);
    printf("\n");
}

#endif
