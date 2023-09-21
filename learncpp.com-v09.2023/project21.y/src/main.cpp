/*
> Step #8

Goal: In this step, we’ll finish our game. Randomize the initial state of the game board. Also, detect when user wins, so after that we can print a win message and quit the game.

We need to be careful about how we randomize our puzzle, because not every puzzle is solvable. For example, there is no way to solve this puzzle:

  1   2   3   4
  5   6   7   8
  9  10  11  12
 13  15  14

If we just blindly randomize the numbers in the puzzle, there is a chance that we will generate such an unsolvable puzzle. With a physical version of the puzzle, we’d randomize the puzzle by sliding tiles in random directions until the tiles were sufficiently mixed. The solution for such a randomized puzzle is to slide each tile in the opposite direction that it was slid to randomize it in the first place. Thus, randomizing puzzles this way always generates a solvable puzzle.

We can have our program randomize the board in the same way.

Once the user has solved the puzzle, the program should print "\n\nYou won!\n\n" and then exit normally.

*/

#include <iostream>
#include "user_input.h"
#include "board.h"


int main()
{
    std::cout << "Welcome to Puzzle 15!\n";

    Board winning_board{};

    Board board{};
    board.randomise();
    std::cout << board;

    char ch{};

    while(true)
    {
        std::cout << "\nGive me a direction with the commands '" << Konstants::up << "' '" << Konstants::right << "' '" << Konstants::down <<"' '" << Konstants::left << "' to move the empty tile around!\n";

        ch = UserInput::getValidatedInput();

        if(ch==Konstants::quit){
            std::cout << "\n\nBye!\n\n";
            return 0;
        }

        board.move0(UserInput::validChar2direction(ch));
        std::cout << board << '\n';

        if(board==winning_board)
        {
            std::cout << "Congratulations! You have won!";
            std::cout << "\n\nBye!\n\n";
            return 0;
        }
    }
    return 0;
}