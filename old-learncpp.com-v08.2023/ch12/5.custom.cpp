/*
 * target: play enough to understand how to use the paragraph n 5
 */

#define DO_NOT_EXECUTE

#include "1.q.h"

int main(int argc, char *argv[])
{
    std::cout << "These are the arguments you inserted: ";
    for(int index {1}; index < argc; ++index)
    {
        std::cout << argv[index] << ' ';
    }
    std::cout << "\nThis is the name of the program: " << argv[0];
    std::cout << "\nThe total number of arguments is: " << argc << '\n';

    return 0;
}


