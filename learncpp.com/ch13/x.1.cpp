/*

Question #1

a) Write a class named Point2d. Point2d should contain two member variables of type double: m_x, and m_y, both defaulted 
to 0.0. Provide a constructor and a print function.

The following program should run:

#include <iostream>

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();

    return 0;
}

This should print:

Point2d(0, 0)
Point2d(3, 4)

b) Now add a member function named distanceTo that takes another Point2d as a parameter, and calculates the distance 
between them. Given two points (x1, y1) and (x2, y2), the distance between them can be calculated as 
std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)). The std::sqrt function lives in header cmath.

The following program should run:

#include <iostream>

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    return 0;
}

This should print:

Point2d(0, 0)
Point2d(3, 4)
Distance between two points: 5

c) Change function distanceTo from a member function to a non-member friend function that takes two Points as parameters. 
Also rename it “distanceFrom”.

The following program should run:

#include <iostream>

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

    return 0;
}

This should print:

Point2d(0, 0)
Point2d(3, 4)
Distance between two points: 5
*/

#include<iostream>
#include<cmath>

class Point2d
{
private:
    double m_x{};
    double m_y{};

public:
    Point2d(double x=0, double y=0) 
    : m_x{x}, m_y{y}
    {}

    void print() const
    {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
    }

    friend double distanceFrom(const Point2d& a, const Point2d& b);
};

double distanceFrom(const Point2d& a, const Point2d& b)
{
    return std::sqrt((a.m_x - b.m_x) * (a.m_x - b.m_x) + (a.m_y - b.m_y) * (a.m_y - b.m_y));
}


int main()
{
    // part a
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();

    // part b
    //std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    // part c
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';


    return 0;
}

