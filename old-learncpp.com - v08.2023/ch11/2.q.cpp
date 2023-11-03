/*
Quiz

1. Declare an array to hold the high temperature (to the nearest tenth of a degree) for each day of a year
 (assume 365 days in a year). Initialize the array with a value of 0.0 for each day.

 2.Set up an enum with the names of the following animals: chicken, dog, cat, elephant, duck, and snake.
 Put the enum in a namespace. Define an array with an element for each of these animals, and use an initializer list
 to initialize each element to hold the number of legs that animal has.

Write a main function that prints the number of legs an elephant has, using the enumerator.
*/

#include<iostream>

double temperature[365] {};

namespace animals
{
    enum kind
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_kind
    };
}

int paws[animals::max_kind] {2, 4, 4, 4,
                             2, 0};

int main(void)
{
    std::cout << "The legs of an elephant are: " << paws[animals::elephant] << "\n";
    return 0;
}