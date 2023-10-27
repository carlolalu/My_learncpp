/*
 *     Write a Pair class that allows you to specify separate types for each of the two values in the pair.

Note: We’re naming this class differently from the previous one because C++ does not currently allow you to “overload” classes that differ only in the number or type of template parameters.

The following program should work:

int main()
{
	Pair<int, double> p1 { 5, 6.7 };
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2 { 2.3, 4 };
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}

and print:

Pair: 5 6.7
Pair: 2.3 4

Hint: To define a template using two different types, separate the two types by a comma in the template parameter declaration. See lesson 10.17 -- Function templates with multiple template types for more information.
 */

#include <iostream>

template<typename T, typename S>
class Pair
{
private:
    T m_first {};
    S m_second {};

public:
    Pair(const T& first, const S& second) : m_first{first}, m_second{second}
    {}

    T& first();
    S& second();

    const T& first() const;
    const S& second() const;
};

template<typename T, typename S>
T& Pair<T,S>::first() {
    return this->m_first;
}

template<typename T, typename S>
S& Pair<T,S>::second() {
    return this->m_second;
}


template<typename T, typename S>
const T& Pair<T,S>::first() const {
    return this->m_first;
}

template<typename T, typename S>
const S& Pair<T,S>::second() const {
    return this->m_second;
}




int main()
{
    Pair<int, double> p1 { 5, 6.7 };
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2 { 2.3, 4 };
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}