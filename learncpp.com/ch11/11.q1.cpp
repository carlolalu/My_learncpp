/*
Write a program that:

    Asks the user how many names they wish to enter.
    Dynamically allocates a std::string array.
    Asks the user to enter each name.
    Calls std::sort to sort the names (See 11.4 --
            Sorting an array using selection sort and 11.8 --
            Pointer arithmetic and array indexing)
    Prints the sorted list of names.

std::string supports comparing strings via the comparison operators < and >.
You don’t need to implement string comparison by hand.

Your output should match this:

How many names would you like to enter? 5
Enter name #1: Jason
Enter name #2: Mark
Enter name #3: Alex
Enter name #4: Chris
Enter name #5: John

Here is your sorted list:
Name #1: Alex
Name #2: Chris
Name #3: Jason
Name #4: John
Name #5: Mark

A reminder

You can use std::getline() to read in names that contain spaces
(see lesson 4.17 -- Introduction to std::string).

A reminder

To use std::sort() with a pointer to an array, calculate begin and end manually

std::sort(array, array + arrayLength);
*/

#include <algorithm>
#include <iostream>

std::string *allocate_array(int lenght) {
  std::string *ptr = {new (std::nothrow) std::string[lenght]{}};
  return ptr;
}

int main(void) {
  std::cout << "How many names would you like to enter? ";
  int lenght{};
  std::cin >> lenght;
  std::string *names = allocate_array(lenght);

  for (int index{}; index < lenght - 1; ++index) {
    std::cout << "Enter name #" << index + 1 << ": ";
    std::string name{};
    std::cin >> name;
    names[index] = name;
  }

  std::sort(names, names + lenght - 1);

  std::cout << "\nHere's your sorted list:\n";
  for (int index{}; index < lenght - 1; ++index) {
    std::cout << "Name #" << index + 1 << ": " << names[index] << "\n";
  }

  return 0;
}
