/*
Question #2

Create a struct to hold a fraction. The struct should have an integer 
numerator and an integer denominator member.

- Write a function to read in a Fraction from the user, and use it to read-in 
two fraction objects. 
- Write another function to multiply two Fractions together 
and return the result as a Fraction (you don’t need to reduce the fraction). 
- Write another function that prints a fraction.

Your program’s output should match the following:

Enter a value for the numerator: 1
Enter a value for the denominator: 2

Enter a value for the numerator: 3
Enter a value for the denominator: 4

Your fractions multiplied together: 3/8

When multiplying two fractions together, the resulting numerator is the product 
of the two numerators, and the resulting denominator is the product of the two 
denominators.
*/

#include<iostream>

struct Fraction
{
    int numerator {};
    int denominator {1};
};

Fraction operator*(const Fraction& frac1, const Fraction& frac2)
{
    return Fraction { frac1.numerator * frac2.numerator, frac1.denominator * frac2.denominator};
}

void print_frac(const Fraction& frac)
{
    std::cout << "Your fraction is: " << frac.numerator << "/" << frac.denominator << std::endl;
}


//takes in expression of the kind "3/4"
Fraction takes_fraction(void)
{
    Fraction frac {};
    std::cout << "Enter a value for the numerator: ";
    std::cin >> frac.numerator;
    std::cout <<"Enter a value for the denominator: ";
    std::cin >> frac.denominator;
    return frac;
}

int main(void)
{
    Fraction frac1 {takes_fraction()};
    print_frac(frac1);
    Fraction frac2 {takes_fraction()};
    print_frac(frac2);
    std::cout <<"\nYour fractions multiplied together become: ";
    print_frac(frac1*frac2);
}