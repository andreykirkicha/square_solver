#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "squaresolver.hpp"

ERRORS reader( double *a )     // TODO: rename read_valid_double
{
    assert(a != NULL);

    if (!scanf("%lf", a) || !finite(*a))
        return INC_INP;

    char tail = getchar();
    if (tail != '\n')
        return INC_INP;

    return OK;
}

INPUT_STATUS input_coefficients( double *a, double *b, double *c )
{
    assert(a != NULL && b != NULL && c != NULL); // TODO: maybe split assert


    // TODO: looks like read_coefficient to me, extract!
    printf("a = ");
    int read_status = reader(a);
    if (read_status != OK)
    {
        error_printer(read_status);
        return FAILED;
    }

    printf("b = ");
    read_status = reader(b);
    if (read_status != OK)
    {
        error_printer(read_status);
        return FAILED;
    }

    printf("c = ");
    read_status = reader(c);
    if (read_status != OK)
    {
        error_printer(read_status);
        return FAILED;
    }

    return SUCCESSFUL;
}

void printer( int res, double x1, double x2 ) // TODO: rename print_roots (or print_equation_solution), you name it!
{
    // TODO: split assert, so you can see which condition failed
    assert(finite(res) && finite(x1) && finite(x2));

    switch(res)
    {
        case TWO_ROOTS:
            printf("%lf, %lf\n", x1, x2);
            break;
        case ONE_ROOT:
            // TODO: is_equal(x1, 0) would make a fine is_zero()
            if (is_equal(x1, 0)) // TODO: extract in function
                x1 = 0;
            printf("%lf\n", x1);
            break;
        case INF_ROOTS:
            printf("any number\n");
            break;
        case NO_ROOTS:
            printf("nothing\n");
            break;
        default:
            // TODO: is this a valid state? Maybe add assert(false)

            // This is an C idiom, get used to it!
            // assert(false && "Unchecked state in switch!");
            // ^~~~~~ is a macro

            // ....... my_string = "My string" // what is type?
            // ^~~~~~~ insert type here

            // const char*
            // ^~~~~ const because string literals are immutable

            // TODO: read about macros, so you know that you can:
            //       #define my_stringifier(x) #x
            //                                 ^ note
            //       printf("%s", my_stringifier(2 + 2)); // Check output!

            // There's also operator '##', read about it as a HW
            printf("unexpected number of roots\n");
            break;
    }
}

// TODO: improve naming, (e.g. skip_to_the_end_of_line)
void clear_buf( FILE *f )
{
    char sym = '0';

    do
    {
        sym = getc(f);
    }
    while (sym != '\n' && sym != EOF);
}
