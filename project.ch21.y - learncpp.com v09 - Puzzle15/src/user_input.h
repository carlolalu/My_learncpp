#ifndef USER_INPUT_H
#define USER_INPUT_H

#include<iostream>
#include<limits>
#include "board.h"
#include "direction.h"
#include "konstants.h"


namespace UserInput
{
    // helper functions
    void ignoreLine()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    bool isValidDirection(const char x)
    {
        return x==Konstants::up || x==Konstants::right || x==Konstants::down || x==Konstants::left;
    }

    bool isValidCommand(const char x)
    {
        return isValidDirection(x) || x==Konstants::quit;
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
        char x{Konstants::unknown_input};

        while( !(isValidCommand(x)) ) {
            x = getChar();
        }

        return x;
    }

    Direction validChar2direction(const char x)
    {
        switch (x) {
            case Konstants::up:
                return Direction{0};
            case Konstants::right:
                return Direction{1};
            case Konstants::down:
                return Direction{2};
            case Konstants::left:
                return Direction{3};
            default:
                assert(false && "the function 'char2direction' was given an invalid directional command!");
        }
    }
}

#endif
