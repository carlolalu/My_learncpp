/*
 * Write a class named RGBA that contains 4 member variables of type std::uint8_t named m_red, m_green, m_blue, and
 * m_alpha (#include cstdint to access type std::uint8_t). Assign default values of 0 to m_red, m_green, and m_blue,
 * and 255 to m_alpha. Create a constructor that uses a member initializer list that allows the user to initialize
 * values for m_red, m_blue, m_green, and m_alpha. Include a print() function that outputs the value of the member
 * variables.

If you need a reminder about how to use the fixed width integers, please review lesson 4.6 -- Fixed-width integers and size_t.

Hint: If your print() function isn’t working correctly, make sure you’re casting uint8_t to an int.

The following code should run:

int main()
{
	RGBA teal{ 0, 127, 127 };
	teal.print();

	return 0;
}

and produce the result:

r=0 g=127 b=127 a=255
 */

#include<iostream>
#include<cstdint>

class RGBA
{
private:
    std::uint8_t m_red {};
    std::uint8_t m_green {};
    std::uint8_t m_blue {};
    std::uint8_t m_alpha {255};

public:
    RGBA(std::uint8_t red = 0, std::uint8_t green = 0, std::uint8_t blue = 0) :
        m_red{red}, m_green{green}, m_blue{blue}
    {
    }

    void print()
    {
        std::cout << "r="<< static_cast<int>(m_red) << ", g=" << static_cast<int>(m_green) << ", b=" <<
                    static_cast<int>(m_blue) << ", a=" << static_cast<int>(m_alpha) << '\n';
    }
};

int main()
{
    RGBA teal{ 0, 127, 127 };
    teal.print();

    return 0;
}