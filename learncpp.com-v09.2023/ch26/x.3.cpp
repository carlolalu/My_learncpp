/*
 *     A string-value pair is a special type of pair where the first value is always a string type, and the second value can be any type. Write a template class named StringValuePair that inherits from a partially specialized Pair class (using std::string as the first type, and allowing the user to specify the second type).

The following program should run:

int main()
{
	StringValuePair<int> svp { "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}

and print:

Pair: Hello 5

Hint: When you call the Pair constructor from the StringValuePair constructor, don’t forget to include the template parameters as part of the Pair class name.
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




template <typename S>
class StringValuePair : public Pair<std::string,S>
{
public:
    StringValuePair(std::string first, S second) : Pair<std::string,S>{first, second}
    {}
};







int main()
{
    StringValuePair<int> svp { "Hello", 5 };
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}