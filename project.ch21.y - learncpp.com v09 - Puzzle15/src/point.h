#ifndef POINT_H
#define POINT_H

#include <iostream>

#include "direction.h"

// we want this grid to be indexed as the indices of a MATRIX: the x grows if we move right and the y grows if we move down!
// pay attention, we index the matrices in the opposite sense: (y,x) instead of (x,y)

constexpr std::size_t g_size {4};

class Point
{
public:
    Point() = default;
    Point(int x=0, int y=0) : m_x{x}, m_y{y}
    {}

    int getX() const;
    int getY() const;

    Point getAdjacentPoint(const Direction& direction);

    bool isOnBoard() const;

    friend bool operator==(const Point& point1, const Point& point2);
    friend bool operator!=(const Point& point1, const Point& point2);

private:
    int m_x {0};
    int m_y {0};
};

std::ostream& operator<<(std::ostream& out, const Point& point);


#endif
