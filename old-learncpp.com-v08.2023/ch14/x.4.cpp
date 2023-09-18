/*
    Extra credit: This one is a little more tricky. A floating point number is a number with a decimal where the number of digits after the decimal can be variable. A fixed point number is a number with a fractional component where the number of digits in the fractional portion is fixed.

In this quiz, we’re going to write a class to implement a fixed point number with two fractional digits (e.g. 12.34, 3.00, or 1278.99). Assume that the range of the class should be -32768.99 to 32767.99, that the fractional component should hold any two digits, that we don’t want precision errors, and that we want to conserve space.

4a) What type of member variable(s) do you think we should use to implement our fixed point number with 2 digits after the decimal? (Make sure you read the answer before proceeding with the next questions)

4b) Write a class named FixedPoint2 that implements the recommended solution from the previous question. If either (or both) of the non-fractional and fractional part of the number are negative, the number should be treated as negative. Provide the overloaded operators and constructors required for the following program to run:

int main()
{
	FixedPoint2 a{ 34, 56 };
	std::cout << a << '\n';

	FixedPoint2 b{ -2, 8 };
	std::cout << b << '\n';

	FixedPoint2 c{ 2, -8 };
	std::cout << c << '\n';

	FixedPoint2 d{ -2, -8 };
	std::cout << d << '\n';

	FixedPoint2 e{ 0, -5 };
	std::cout << e << '\n';

	std::cout << static_cast<double>(e) << '\n';

	return 0;
}

This program should produce the result:

34.56
-2.08
-2.08
-2.08
-0.05
-0.05

Hint: To output your number, first cast it to a double.

4c) Now add a constructor that takes a double. The follow program should run:

int main()
{
	// Handle cases where the argument is representable directly
	FixedPoint2 a{ 0.01 };
	std::cout << a << '\n';

	FixedPoint2 b{ -0.01 };
	std::cout << b << '\n';

	// Handle cases where the argument has some rounding error
	FixedPoint2 c{ 5.01 }; // stored as 5.0099999... so we'll need to round this
	std::cout << c << '\n';

	FixedPoint2 d{ -5.01 }; // stored as -5.0099999... so we'll need to round this
	std::cout << d << '\n';

	// Handle case where the argument's decimal rounds to 100 (need to increase base by 1)
	FixedPoint2 e{ 106.9978 }; // should be stored with base 107 and decimal 0
	std::cout << e << '\n';

	FixedPoint2 f{ 1.9 }; // make sure we handle single digit decimal
	std::cout << f;

	return 0;
}

This program should produce the result

0.01
-0.01
5.01
-5.01
107
1.9

Recommendation: This one will be a bit tricky. Do this one in three steps. First, solve for the cases where the double parameter is representable directly (cases a & b above). Then, update your code to handle the cases where the double parameter has a rounding error (cases c & d). Lastly, handle the edge case where the decimal rounds up to 100 (case e).
*/

#include <iostream>
#include <cmath>

template<typename T>
T sign(const T& num)
{
    if(num<0){
        return -1;
    } else if (num>0) {
        return 1;
    } else {
        return 0;
    }
}



class FixedPoint2
{
public:
    // usual constructor
    FixedPoint2(std::int16_t int_part, std::int8_t frac_part) : m_int_part{int_part}, m_frac_part{frac_part}
    {}

    // constructor which handles the double
    // FixedPoint2(double num);

    operator double() const;

    friend std::ostream& operator<<(std::ostream& out, const FixedPoint2& num);

private:
    std::int16_t m_int_part{};
    std::int8_t m_frac_part{};
};

FixedPoint2::operator double() const
{
    double abs = std::abs(static_cast<double>(m_int_part));

    if(m_frac_part!=0){
        abs = abs + (std::abs(static_cast<double>(m_frac_part)/100));
    }
    
    if( sign<std::int16_t>(m_int_part)<0 || sign<std::int8_t>(m_frac_part)<0 ){
        abs = -abs;
    }
    return abs;
}

std::ostream& operator<<(std::ostream& out, const FixedPoint2& num)
{
    out << double(num);
    return out;
}

FixedPoint2



int main()
{
	// Handle cases where the argument is representable directly
	FixedPoint2 a{ 0.01 };
	std::cout << a << '\n';

	FixedPoint2 b{ -0.01 };
	std::cout << b << '\n';

	// Handle cases where the argument has some rounding error
	FixedPoint2 c{ 5.01 }; // stored as 5.0099999... so we'll need to round this
	std::cout << c << '\n';

	FixedPoint2 d{ -5.01 }; // stored as -5.0099999... so we'll need to round this
	std::cout << d << '\n';

	// Handle case where the argument's decimal rounds to 100 (need to increase base by 1)
	FixedPoint2 e{ 106.9978 }; // should be stored with base 107 and decimal 0
	std::cout << e << '\n';

	FixedPoint2 f{ 1.9 }; // make sure we handle single digit decimal
	std::cout << f;

	return 0;
}