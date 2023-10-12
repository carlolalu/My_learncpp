/*
 * a) Write an Apple class and a Banana class that are derived from a common Fruit class. Fruit should have two members: a name and a color.

The following program should run:

int main()
{
	Apple a{ "red" };
	Banana b{};

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";

	return 0;
}

And produce the result:

My apple is red.
My banana is yellow.



 b) Add a new class to the previous program called GrannySmith that inherits from Apple.

The following program should run:

int main()
{
	Apple a{ "red" };
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}

And produce the result:

My apple is red.
My banana is yellow.
My granny smith apple is green.

 */
#include <string>
#include <string_view>
#include <iostream>

class Fruit
{
private:
    std::string m_name {};
    std::string m_color {};

public:
    Fruit(std::string name, std::string color) : m_name {name}, m_color {color}
    {}

    std::string_view getName() const
    {
        return m_name;
    }

    std::string_view getColor() const
    {
        return m_color;
    }
};

class Banana : public Fruit
{
private:
public:
    Banana(std::string name="banana", std::string color="yellow") : Fruit{name, color}
    {}
};

class Apple : public Fruit
{
private:
protected:
    Apple(std::string name, std::string color) : Fruit(name, color)
    {}

public:
    Apple(std::string color="red") : Fruit{"apple", color}
    {}
};

class GrannySmith : public Apple
{
private:
public:
    GrannySmith() : Apple{"granny smith apple", "green"}
    {}
};


int main()
{
    Apple a{ "red" };
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}