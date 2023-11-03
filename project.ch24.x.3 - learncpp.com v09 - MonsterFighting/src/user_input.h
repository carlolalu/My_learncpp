#ifndef USER_INPUT_H
#define USER_INPUT_H

#include<iostream>
#include<limits>


namespace UserInput
{
    // helper functions
    void ignoreLine()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    bool isValidCommand(const char x)
    {
        return (x=='f' || x=='r');
    }

    bool isValidYesNoInput(char x)
    {
        return (x=='y' || x=='n');
    }

    char getChar()
    {
        char atom{};
        std::cin >> atom;
        ignoreLine();       // in case the user wrote more than one char in the line
        return atom;
    }

    // actual ui
    char getValidatedInput()
    {
        char x{};

        while( !(isValidCommand(x)) ) {
            x = getChar();
        }

        return x;
    }

    char getValidatedYesNoInput()
    {
        char x{};

        while( !(isValidYesNoInput(x)) ) {
            x = getChar();
        }

        return x;
    }
}

#endif
