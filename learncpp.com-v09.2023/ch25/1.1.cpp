/*
 * Quiz time

    Our Animal/Cat/Dog example above doesn’t work like we want because a reference or pointer to an Animal can’t access the derived version of speak() needed to return the right value for the Cat or Dog. One way to work around this issue would be to make the data returned by the speak() function accessible as part of the Animal base class (much like the Animal’s name is accessible via member m_name).

Update the Animal, Cat, and Dog classes in the lesson above by adding a new member to Animal named m_speak. Initialize it appropriately. The following program should work properly:

#include <array>
#include <iostream>

int main()
{
    const Cat fred{ "Fred" };
    const Cat misty{ "Misty" };
    const Cat zeke{ "Zeke" };

    const Dog garbo{ "Garbo" };
    const Dog pooky{ "Pooky" };
    const Dog truffle{ "Truffle" };

    // Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
    const auto animals{ std::to_array<const Animal*>({ &fred, &garbo, &misty, &pooky, &truffle, &zeke }) };

    // Before C++20, with the array size being explicitly specified
    // const std::array<const Animal*, 6> animals{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };

    for (const auto animal : animals)
    {
        std::cout << animal->getName() << " says " << animal->speak() << '\n';
    }

    return 0;
}

    Why is the above solution non-optimal?

Hint: Think about the future state of Cat and Dog where we want to differentiate Cats and Dogs in more ways.
Hint: Think about the ways in which having a member that needs to be set at initialization limits you.
 */

#include <iostream>
#include <string_view>
#include <string>
#include <array>

class Animal
{
protected:
    std::string m_name;
    std::string m_speak;

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(std::string_view name, std::string speak)
            : m_name{ name }, m_speak{speak}
    {
    }

    // To prevent slicing (covered later)
    Animal(const Animal&) = default;
    Animal& operator=(const Animal&) = default;

public:
    std::string_view getName() const { return m_name; }
    std::string_view speak() const { return m_speak; }
};

class Cat: public Animal
{
public:
    Cat(std::string_view name)
            : Animal{ name , "Meow"}
    {
    }
};

class Dog: public Animal
{
public:
    Dog(std::string_view name)
            : Animal{ name, "Woof"}
    {
    }
};



int main()
{
    const Cat fred{ "Fred" };
    const Cat misty{ "Misty" };
    const Cat zeke{ "Zeke" };

    const Dog garbo{ "Garbo" };
    const Dog pooky{ "Pooky" };
    const Dog truffle{ "Truffle" };

    // Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
    const auto animals{ std::to_array<const Animal*>({ &fred, &garbo, &misty, &pooky, &truffle, &zeke }) };

    // Before C++20, with the array size being explicitly specified
    // const std::array<const Animal*, 6> animals{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };

    for (const auto animal : animals)
    {
        std::cout << animal->getName() << " says " << animal->speak() << '\n';
    }

    return 0;
}









