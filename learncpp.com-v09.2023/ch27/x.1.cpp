/*     Write a Fraction class that has a constructor that takes a numerator and a denominator. If the user passes in a denominator of 0, throw an exception of type std::runtime_error (included in the stdexcept header). In your main program, ask the user to enter two integers. If the Fraction is valid, print the fraction. If the Fraction is invalid, catch a std::exception, and tell the user that they entered an invalid fraction.

Here’s what one run of the program should output:

Enter the numerator: 5
Enter the denominator: 0
Invalid denominator
*/

#include <iostream>
#include <stdexcept>
#include <exception>

class Fraction
{
private:
	int m_numerator {};
	int m_denominator {};

public:
	Fraction(int numerator, int denominator)
	: m_numerator(numerator), m_denominator(denominator)
	{
		if(!denominator) { throw std::runtime_error{"Invalid denominator"}; }
	}
};


int main(void)
{
	std::cout << "Enter the numerator of your fraction: ";
	int numerator {};
	std::cin >> numerator;

	std::cout << "Enter the denominator of your fraction: ";
	int denominator {};
	std::cin >> denominator;

	try { Fraction fraction{numerator, denominator}; }

	catch(std::exception& exception)
	{
		std::cerr << exception.what() << '\n';
		return 0;
	}

	return 0;
}
