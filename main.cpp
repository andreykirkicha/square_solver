#include <stdio.h>
#include "squaresolver.hpp"
#include "test.hpp"

int main(int argc, char *argv[])
{
    bool session_continue = true;

    while (session_continue)
        request(argv[1], &session_continue);

    return 0;
}
