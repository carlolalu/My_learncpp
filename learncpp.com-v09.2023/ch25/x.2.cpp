/*
 *
 * 2a) Create an abstract class named Shape. This class should have three functions: a pure virtual print function that takes and returns a std::ostream&, an overloaded operator<< and an empty virtual destructor.
 *
 *
 *
 *
 *
 *
 * 2b) Derive two classes from Shape: a Triangle, and a Circle. The Triangle should have 3 Points as members. The Circle should have one center Point, and an integer radius. Overload the print() function so the following program runs:

int main()
{
    Circle c{ Point{ 1, 2 }, 7 };
    std::cout << c << '\n';

    Triangle t{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }};
    std::cout << t << '\n';

    return 0;
}

This should print:

Circle(Point(1, 2), radius 7)
Triangle(Point(1, 2), Point(3, 4), Point(5, 6))

Here’s a Point class you can use:

class Point
{
private:
	int m_x{};
	int m_y{};

public:
	Point(int x, int y)
		: m_x{ x }, m_y{ y }
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		return out << "Point(" << p.m_x << ", " << p.m_y << ')';
	}
};
 *
 *
 *
 *
 *
 *
 *
 *
 *
2c) Given the above classes (Point, Shape, Circle, and Triangle), finish the following program:

#include <vector>
#include <iostream>

int main()
{
	std::vector<Shape*> v{
	  new Circle{Point{ 1, 2 }, 7},
	  new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
	  new Circle{Point{ 7, 8 }, 3}
	};

	// print each shape in vector v on its own line here

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	// delete each element in the vector here

	return 0;
}

The program should print the following:

Circle(Point(1, 2), radius 7)
Triangle(Point(1, 2), Point(3, 4), Point(5, 6))
Circle(Point(7, 8), radius 3)
The largest radius is: 7

Hint: You’ll need to add a getRadius() function to Circle, and downcast a Shape* into a Circle* to access it.
 *
 *
 *
 *
 */

#include <iostream>
#include <array>
#include <vector>

class Point
{
private:
    int m_x{};
    int m_y{};

public:
    Point(int x=0, int y=0)
            : m_x{ x }, m_y{ y }
    {}

    friend std::ostream& operator<<(std::ostream& out, const Point& p);
};

std::ostream& operator<<(std::ostream& out, const Point& p)
{
    return out << "Point(" << p.m_x << ", " << p.m_y << ')';
}



class Shape
{
public:
    virtual std::ostream& print(std::ostream& out) const = 0;
    friend std::ostream& operator <<(std::ostream& out, const Shape& shape);
    virtual ~Shape() = default;
};

std::ostream& Shape::print(std::ostream& out) const
{
    return out;
}

class Circle : public Shape
{
public:
    Circle(const Point& center, const double radius) : m_center{center}, m_radius{radius}
    {}

    std::ostream& print(std::ostream& out) const override;
    double getRadius() const;

private:
    Point m_center {};
    double m_radius{};
};

std::ostream& Circle::print(std::ostream& out) const
{
    out << "Circle(" << m_center << ", radius " << m_radius << ")";
    return out;
}

double Circle::getRadius() const
{
    return m_radius;
}


class Triangle : public Shape
{
public:
    Triangle(const Point& vertex1, const Point& vertex2, const Point& vertex3)
        : m_vertices({vertex1, vertex2, vertex3})
    {}

    std::ostream& print(std::ostream& out) const override;

private:
    // these should be ordered counter-clockwise
    std::array<Point, 3> m_vertices { {Point{0,0}, Point{1,0}, Point{0,1}} };
};

std::ostream& Triangle::print(std::ostream& out) const
{
    out << "Triangle(";

    std::size_t counter {0};
    for(const Point& vertex : m_vertices)
    {
        out << vertex;
        if( ++counter < m_vertices.size() ) { out << ", "; }
    }
    out << ")";
    return out;
}

std::ostream& operator<< (std::ostream& out, const Shape& shape)
{
    return shape.print(out);
}


double getLargestRadius(std::vector<Shape*> v)
{
    double max {};
    double localCaliber {};
    Circle* circlePtr{};

    for(Shape* shape : v)
    {
        circlePtr = dynamic_cast<Circle*>(shape);
        if(circlePtr){
            localCaliber = circlePtr->getRadius();
            if( max < localCaliber ){
                max = localCaliber;
            }
        }
    }
    return max;
}


int main()
{
    std::vector<Shape*> v{
            new Circle{Point{ 1, 2 }, 7},
            new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
            new Circle{Point{ 7, 8 }, 3}
    };

    for(const Shape* shape : v)
    {
        std::cout << *shape << '\n';
    }

    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

    for(Shape* shape : v)
    {
        delete(shape);
    }

    return 0;
}