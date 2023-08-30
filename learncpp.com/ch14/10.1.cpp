/*
Write a class named MyString that holds a std::string. Overload operator<< to output the string. Overload operator() to return the substring that starts at the index of the first parameter (as a MyString). The length of the substring should be defined by the second parameter.

The following code should run:

int main()
{
    MyString s { "Hello, world!" };
    std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}

This should print

world

Hint: You can use std::string::substr to get a substring of a std::string.
*/

#include<iostream>

class MyString
{
private:
    std::string m_data{};

public:

    MyString(std::string data={}) : m_data{data}
    {}

    friend std::ostream& operator<<(std::ostream& out, const MyString& mystring);

    MyString operator()(std::size_t start, std::size_t lenght);
};

std::ostream& operator<<(std::ostream& out, const MyString& mystring){
    out << mystring.m_data;
    return out;
}


MyString MyString::operator()(std::size_t start, std::size_t lenght){
    return {m_data.substr(start, lenght)};
}

int main()
{
    MyString s { "Hello, world!" };
    std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}


