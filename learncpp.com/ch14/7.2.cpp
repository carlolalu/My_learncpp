/* 
Add an overloaded operator<< and operator< to the Car class at the top of the lesson so that the following program compiles:

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
  std::vector<Car> cars{
    { "Toyota", "Corolla" },
    { "Honda", "Accord" },
    { "Toyota", "Camry" },
    { "Honda", "Civic" }
  };

  std::sort(cars.begin(), cars.end()); // requires an overloaded operator<

  for (const auto& car : cars)
    std::cout << car << '\n'; // requires an overloaded operator<<

  return 0;
}

This program should produce the following output:

(Honda, Accord)
(Honda, Civic)
(Toyota, Camry)
(Toyota, Corolla)

If you need a refresher on std::sort, we talk about it in lesson 11.4 -- Sorting an array using selection sort.
*/


#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <string_view>

class Car
{
private:
    std::string m_make;
    std::string m_model;

public:
    Car(std::string_view make, std::string_view model)
        : m_make{ make }, m_model{ model }
    {
    }

    friend bool operator== (const Car& c1, const Car& c2);
    friend bool operator!= (const Car& c1, const Car& c2);

    friend std::ostream& operator<<(std::ostream& out, const Car& car);

    friend bool operator<(const Car& car1, const Car& car2);
};

bool operator== (const Car& c1, const Car& c2)
{
    return (c1.m_make == c2.m_make &&
            c1.m_model == c2.m_model);
}

bool operator!= (const Car& c1, const Car& c2)
{
    return (c1.m_make != c2.m_make ||
            c1.m_model != c2.m_model);
}

std::ostream& operator<<(std::ostream& out, const Car& car){
    std::cout << "Car(" << car.m_make << ',' << car.m_model << ')' << '\n';
    return out;
}

// nobody really explained which partial order we should use, thus I will implement smt random
bool operator<(const Car& car1, const Car& car2){
    return car1.m_make == car2.m_make? (car1.m_model < car2.m_model) : (car1.m_make < car2.m_make);
}


int main()
{
std::vector<Car> cars{
    { "Toyota", "Corolla" },
    { "Honda", "Accord" },
    { "Toyota", "Camry" },
    { "Honda", "Civic" }
};

  std::sort(cars.begin(), cars.end()); // requires an overloaded operator<

for (const auto& car : cars)
    std::cout << car << '\n'; // requires an overloaded operator<<

return 0;
}