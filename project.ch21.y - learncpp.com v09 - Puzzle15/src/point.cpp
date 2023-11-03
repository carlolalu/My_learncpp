#include "point.h"

int Point::getX() const
{
    return m_x;
}

int Point::getY() const
{
    return m_y;
}

Point Point::getAdjacentPoint(const Direction& direction)
{
    switch(direction.getTowards())
    {
        case 0: return Point{m_x, m_y-1};
        case 1: return Point{m_x+1, m_y};
        case 2: return Point{m_x, m_y+1};
        case 3: return Point{m_x-1, m_y};
        default: std::cout << "The given direction is invalid\n"; return *this;
    }
}

bool Point::isOnBoard() const
{
    int size { static_cast<int>(g_size) };
    return ( m_y>=0 && m_y<size && m_x>=0 && m_x<size );
}

bool operator==(const Point& point1, const Point& point2)
{
    return point1.m_x==point2.m_x && point1.m_y==point2.m_y;
}


bool operator!=(const Point& point1, const Point& point2)
{
    return !(point1==point2);
}


std::ostream& operator<<(std::ostream& out, const Point& point)
{
    out << "(" << point.getX() << "," << point.getY() << ")";
    return out;
}











