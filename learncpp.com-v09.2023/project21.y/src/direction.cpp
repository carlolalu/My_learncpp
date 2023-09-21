#include"direction.h"


Direction Direction::getRandom()
{
    return Direction{Random::get<int>(0,3)};
}

Direction::Possible Direction::getTowards() const
{
    return m_towards;
}

Direction Direction::operator-() const
{
    if( m_towards <= 1 )
    {
        return Direction{ m_towards+2 };
    } else
    {
        return Direction{ m_towards-2 };
    }
}


std::ostream& operator<< (std::ostream& out, const Direction& direction)
{
    switch(direction.getTowards())
    {
        case 0: out << Konstants::up; break;
        case 1: out << Konstants::right; break;
        case 2: out << Konstants::down; break;
        case 3: out << Konstants::left; break;
        default: out << "unknown direction"; break;
    }
    return out;
}


