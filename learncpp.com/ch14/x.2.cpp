/*
Write a class named Average that will keep track of the average of all integers passed to it. Use two members: The first one should be type std::int32_t, and used to keep track of the sum of all the numbers you’ve seen so far. The second should be of type std::int8_t, and used to keep track of how many numbers you’ve seen so far. You can divide them to find your average.


*/

#include <iostream>
#include <cstdint>


class Average
{
private:
    std::int32_t m_total_sum{};
    std::int8_t m_element_no{};

public:
    Average operator+(int element);

    Average& operator+=(int element);

    friend std::ostream& operator<< (std::ostream& out, const Average& avg);
};

Average Average::operator+(int element)
{
    m_total_sum += element;
    ++m_element_no;
    return *this;
}

Average& Average::operator+=(int element)
{
    *this = *this + element;
    return *this;
}

std::ostream& operator<< (std::ostream& out, const Average& avg)
{
    if(avg.m_element_no==0){
        out << 0;
        return out;
    }

    out << (avg.m_total_sum/static_cast<double>(avg.m_element_no));
    return out;
}



int main()
{
	Average avg{};

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}