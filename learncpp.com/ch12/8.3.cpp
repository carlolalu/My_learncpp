/* We’re going to write a little game with square numbers (numbers which can be created by multiplying an integer with
 * itself (1, 4, 9, 16, 25, …)).

Ask the user to input 2 numbers, the first is the number to start at, the second is the amount of numbers to generate.
 Generate square numbers in the range that was chosen by the user. Then generate a random integer from 2 to 4, and
 multiple each square number by the random number. You can assume that the user enters valid numbers.

The user has to calculate which numbers have been generated. The program checks if the user guessed correctly and
 removes the guessed number from the list. If the user guessed wrong, the game is over and the program prints the
 number that was closest to the user’s final guess, but only if the final guess was not off by more than 4.

 Use std::find (11.18 -- Introduction to standard library algorithms) to search for a number in the list.
Use std::vector::erase to remove an element, e.g.

auto found{ std::find(_________________) };

// Make sure the element was found

myVector.erase(found);

Use std::min_element and a lambda to find the number closest to the user’s guess. std::min_element works analogous to
 std::max_element from the previous quiz.*/


#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
#include<random>
#include<chrono>
#include<cmath>
#include<ctime>

namespace config
{
    constexpr int min_multiplier { 2 };
    constexpr int max_multiplier { 4 };
    constexpr int max_distance { 4 };
}


int random(int min, int max)
{
    static std::mt19937_64 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

    return std::uniform_int_distribution{ min, max }(mt);
}


std::vector<int> generate_vector(int start, int how_many, int factor)
{
    std::vector<int> list( static_cast<std::size_t>(how_many) );
    for(int index {}; index < how_many; ++index)
    {
        list.at(static_cast<std::size_t>(index)) = factor*(start+index)*(start+index);
    }
    return list;
}


void play_game(std::vector<int>& list)
{
    int user_input {};

    do{
        std::cin >> user_input;
        auto found {std::find(list.begin(), list.end(), user_input)};

        if( found == list.end() ) {
            break;
        }

        list.erase(found);
        std::cout << "Nice! " << list.size() << " left!\n";
    }while(!list.empty());

    if (list.empty()){
        std::cout << "Nice! You found all numbers, good job!\n";
    } else {
        auto closest = *std::min_element(list.begin(),list.end(), [&] (const int& a, const int& b) {
                        return std::abs(user_input-a) < std::abs(user_input-b);});
        if(std::abs(closest-user_input) < config::max_distance){
            std::cout << user_input << " is wrong! Try " << closest << " next time.\n";
        } else {
            std::cout << user_input << " is wrong!\n";
        }
    }
}

int main(void)
{
    std::cout << "Start where? ";
    int starting_num {};
    std::cin >> starting_num;

    std::cout << "How many? ";
    int count {};
    std::cin >> count;

    int multiplier{ random(config::min_multiplier,config::max_multiplier) };

    std::vector<int> numbers { generate_vector(starting_num, count, multiplier ) };
    std::cout << "\nI generated " << count << " square numbers. Can you guess each number after multiplying it by " << multiplier << "?\n";

    play_game(numbers);

    return 0;
}