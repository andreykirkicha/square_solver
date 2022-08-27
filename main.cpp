#include <stdio.h>
#include "squaresolver.hpp"
#include "test.hpp"

int main(int argc, char *argv[])
{
    bool session = CONTINUE;

    while (session)
        ask_question(argv, &session);

    return 0;
}
