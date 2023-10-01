/*
 * Convert the following program from using a normal pointer to using std::unique_ptr where appropriate:

#include <iostream>

class Fraction
{
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
	{
		out << f1.m_numerator << '/' << f1.m_denominator;
		return out;
	}
};

void printFraction(const Fraction* ptr)
{
	if (ptr)
		std::cout << *ptr << '\n';
	else
		std::cout << "No fraction\n";
}

int main()
{
	auto* ptr{ new Fraction{ 3, 5 } };

	printFraction(ptr);

	delete ptr;

	return 0;
}
 */
#include <iostream>
#include <memory>


class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    Fraction(int numerator = 0, int denominator = 1) :
            m_numerator{ numerator }, m_denominator{ denominator }
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
    {
        out << f1.m_numerator << '/' << f1.m_denominator;
        return out;
    }
};

void printFraction(const Fraction* ptr_2)
{
    if (ptr_2)
        std::cout << *ptr_2 << '\n';
    else
        std::cout << "No fraction\n";
}

int main()
{
    auto ptr { std::make_unique<Fraction>(3,5)};

    printFraction (ptr.get());

    return 0;
}