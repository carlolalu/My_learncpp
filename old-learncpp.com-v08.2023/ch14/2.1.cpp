/*

a) Write a class named Fraction that has an integer numerator and denominator member. Write a print() function that 
prints out the fraction.

The following code should compile:

#include <iostream>

int main()
{
    Fraction f1{ 1, 4 };
    f1.print();

    Fraction f2{ 1, 2 };
    f2.print();

    return 0;
}

This should print:

1/4
1/2

b) Add overloaded multiplication operators to handle multiplication between a Fraction and integer, and between two Fractions. 
Use the friend function method.

Hint: To multiply two fractions, first multiply the two numerators together, and then multiply the two denominators together. 
To multiply a fraction and an integer, multiply the numerator of the fraction by the integer and leave the denominator alone.

The following code should compile:

#include <iostream>

int main()
{
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    return 0;
}

This should print:

2/5
3/8
6/40
4/5
6/8
6/24

c) Why does the program continue to work correctly if we remove the operators for integer multiplication from the previous solution?

// We can remove these operators, and the program continues to work
Fraction operator*(const Fraction& f1, int value);
Fraction operator*(int value, const Fraction& f1);

d) If we remove the const from the Fraction * Fraction operator, the following line from the main function no longer works. Why?

// The non-const multiplication operator looks like this
Fraction operator*(Fraction& f1, Fraction& f2)

// This doesn't work anymore
Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };


e) Extra credit: the fraction 2/4 is the same as 1/2, but 2/4 is not reduced to the lowest terms. We can reduce any given 
fraction to lowest terms by finding the greatest common divisor (GCD) between the numerator and denominator, and then 
dividing both the numerator and denominator by the GCD.

std::gcd was added to the standard library in C++17 (in the <numeric> header).

If you’re on an older compiler, you can use this function to find the GCD:

#include <cmath> // for std::abs

int gcd(int a, int b) {
    return (b == 0) ? std::abs(a) : gcd(b, a % b);
}

Write a member function named reduce() that reduces your fraction. Make sure all fractions are properly reduced.

The following should compile:

#include <iostream>

int main()
{
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    Fraction f7{0, 6};
    f7.print();

    return 0;
}

And produce the result:

2/5
3/8
3/20
4/5
3/4
1/4
0/1


*/

#include <iostream>
#include <numeric>


class Fraction
{

public:
    Fraction(const int numerator=0, const int denominator=1) : m_numerator{numerator}, m_denominator{denominator}
    {}

    int getNumerator() const {
        return m_numerator;
    }

    int getDenominator() const {
        return m_denominator;
    }

    void print() const {
        std::cout << m_numerator << '\\' << m_denominator << '\n';
    }

    // reduction
    Fraction reduce(){
        const int gcd {std::gcd(m_numerator, m_denominator)};
        return { m_numerator/gcd, m_denominator/gcd };
    }

    // operations
    friend Fraction operator*(const Fraction& frac1, const Fraction& frac2);
    friend Fraction operator*(const Fraction& frac1, const int int2);
    friend Fraction operator*(const int int2, const Fraction& frac1);

private:
    int m_numerator{0};
    int m_denominator{1};
};


// definition of the functions
Fraction operator*(const Fraction& frac1, const Fraction& frac2) {
    return Fraction{frac1.m_numerator * frac2.m_numerator, frac1.m_denominator * frac2.m_denominator}.reduce();
}

Fraction operator*(const Fraction& frac1, const int int2) {
    return Fraction{frac1.m_numerator * int2, frac1.m_denominator}.reduce();
}

Fraction operator*(const int int2, const Fraction& frac1) {
    return frac1*int2;
}



int main()
{
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    Fraction f7{0, 6};
    f7.print();

    return 0;
}