/*
 *     Let’s implement our Fruit example that we talked about in our introduction to inheritance. Create a Fruit base class that contains two private members: a name (std::string), and a color (std::string). Create an Apple class that inherits Fruit. Apple should have an additional private member: fiber (double). Create a Banana class that also inherits Fruit. Banana has no additional members.

The following program should run:

#include <iostream>

int main()
{
	const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';

	return 0;
}

And print the following:

Apple(Red delicious, red, 4.2)
Banana(Cavendish, yellow)

Hint: Because a and b are const, you’ll need to mind your consts. Make sure your parameters and functions are appropriately const.
 */
#include <string>
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
    Banana(std::string name, std::string color="yellow") : Fruit{name, color}
    {}

    friend std::ostream& operator << (std::ostream& out, const Banana& banana)
    {
        out << "(" << banana.getName() << ", " << banana.getColor() << ")";
        return out;
    }
};

class Apple : public Fruit
{
private:
    double m_fiber {};

public:
    Apple(std::string name, std::string color, double fiber) : Fruit{name, color} , m_fiber {fiber}
    {}

    double getFiber() const
    {
        return m_fiber;
    }

    friend std::ostream& operator << (std::ostream& out, const Apple& apple)
    {
        out << "(" << apple.getName() << ", " << apple.getColor() << ", " << apple.getFiber() << ")";
        return out;
    }
};



int main()
{
    const Apple a{ "Red delicious", "red", 4.2 };
    std::cout << a << '\n';

    const Banana b{ "Cavendish", "yellow" };
    std::cout << b << '\n';

    return 0;
}