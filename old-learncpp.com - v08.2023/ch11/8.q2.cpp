/*
Write a function named findValue that takes a pointer to the beginning and a pointer
 to the end (1 element past the last) of an array, as well as a value. The function
 should search for the given value and return a pointer to the first element with that value,
 or the end pointer if no element was found. The following program should run:

#include <iostream>
#include <iterator>

// ...

int main()
{
    int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };

    // Search for the first element with value 20.
    int* found{ findValue(std::begin(arr), std::end(arr), 20) };

    // If an element with value 20 was found, print it.
    if (found != std::end(arr))
    {
        std::cout << *found << '\n';
    }

    return 0;
}

Tip

        std::begin and std::end return an int*. The call to findValue is equivalent to

int* found{ findValue(arr, arr + std::size(arr), 20) };

 */


#include <iostream>
#include <iterator>

int* findValue(int* begin, int* end, int num)
{
    while(*begin != num && begin != end)
    {
        ++begin;
    }
    return begin;
}

int main()
{
    int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };

    // Search for the first element with value 20.
    int* found{ findValue(std::begin(arr), std::end(arr), 20) };

    // If an element with value 20 was found, print it.
    if (found != std::end(arr))
    {
        std::cout << *found << '\n';
    }

    return 0;
}
