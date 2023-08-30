/*
    Add the six comparison operators to the Fraction class so that the following program compiles:

#include <iostream>
#include <numeric> // for std::gcd

class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
		// We put reduce() in the constructor to ensure any new fractions we make get reduced!
		// Any fractions that are overwritten will need to be re-reduced
		reduce();
	}

	void reduce()
	{
		int gcd{ std::gcd(m_numerator, m_denominator) };
		if (gcd)
		{
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.m_numerator << '/' << f1.m_denominator;
	return out;
}

int main()
{
	Fraction f1{ 3, 2 };
	Fraction f2{ 5, 8 };

	std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
	std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
	std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
	std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
	std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
	std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';
	return 0;
}
*/

#include <iostream>
#include <numeric> // for std::gcd

class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
		// We put reduce() in the constructor to ensure any new fractions we make get reduced!
		// Any fractions that are overwritten will need to be re-reduced
		reduce();
	}

	void reduce()
	{
		int gcd{ std::gcd(m_numerator, m_denominator) };
		if (gcd)
		{
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);

    // comparison
    friend bool operator==(const Fraction& frac1, const Fraction& frac2);
    friend bool operator!=(const Fraction& frac1, const Fraction& frac2);

    friend bool operator<(const Fraction& frac1, const Fraction& frac2);
    friend bool operator>(const Fraction& frac1, const Fraction& frac2);
    friend bool operator<=(const Fraction& frac1, const Fraction& frac2);
    friend bool operator>=(const Fraction& frac1, const Fraction& frac2);


};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.m_numerator << '/' << f1.m_denominator;
	return out;
}


// here we should better checked that everything is reduced before comparing
bool operator==(const Fraction& frac1, const Fraction& frac2){
    return ( frac1.m_numerator==frac2.m_numerator && frac1.m_denominator==frac2.m_denominator );
}

bool operator!=(const Fraction& frac1, const Fraction& frac2){
    return !(frac1==frac2);
}

// if here we start to work with negative numbers we could incur into some problems because both the num and the denom might be negative
bool operator<(const Fraction& frac1, const Fraction& frac2){
    return ( frac1.m_numerator * frac2.m_denominator < frac2.m_numerator * frac1.m_denominator );
}

bool operator>(const Fraction& frac1, const Fraction& frac2){
    return ( frac2 < frac1 );
}

bool operator<=(const Fraction& frac1, const Fraction& frac2){
    return !( frac1 > frac2 );
}

bool operator>=(const Fraction& frac1, const Fraction& frac2){
    return !( frac1 < frac2 );
}

int main()
{
	Fraction f1{ 3, 2 };
	Fraction f2{ 5, 8 };

	std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
	std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
	std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
	std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
	std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
	std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';
	return 0;
}
