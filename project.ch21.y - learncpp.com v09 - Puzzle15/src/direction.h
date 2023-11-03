#ifndef DIRECTION_H
#define DIRECTION_H

#include<iostream>
#include<assert.h>

#include "konstants.h"
#include "random.h"

class Direction
{
public:
    enum Possible
    {
        up,
        right,
        down,
        left,

        max_possible,
    };

    static Direction getRandom();

    Direction(Possible possible=up) : m_towards{ possible }
    {
        assert(possible>=0 && possible<=3 && "direction initialised with invalid number");
    }

    Direction(int num=up) : Direction(static_cast<Direction::Possible>(num))
    {}

    Possible getTowards() const;

    Direction operator-() const;

    friend std::ostream& operator<< (std::ostream& out, const Direction& direction);

private:
    Possible m_towards {up};
};

#endif
