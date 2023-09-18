/*
 In the quiz for lesson 7.10 -- For statements, we implemented a game called FizzBuzz for the 
 numbers three,
 five, and seven.

In this quiz, implement the game as follows:

    Numbers divisible by only 3 should print “fizz”.
    Numbers divisible by only 5 should print “buzz”.
    Numbers divisible by only 7 should print “pop”.
    Numbers divisible by only 11 should print “bang”.
    Numbers divisible by only 13 should print “jazz”.
    Numbers divisible by only 17 should print “pow”.
    Numbers divisible by only 19 should print “boom”.
    Numbers divisible by more than one of the above should print each of the words associated 
    with its divisors.
    Numbers not divisible by any of the above should just print the number.

Use an array to hold the divisors, and another array to hold the words (as type std::string_view). 
If the arrays do
not have the same length, the program should fail to compile. Produce output for 150 numbers.
 */

#include<iostream>



int main(void)
{
	std::string words[7] = {"fizz","buzz","pop","bang","jazz","pow","boom"};
	int divisors[] = {3,5,7,11,13,17,19};

	bool divided {};
	for(int actual {}; actual < 151; ++actual)
	{
		divided = {};
		for(int index {}; index < static_cast<int>(sizeof(divisors)/sizeof(divisors[0])); ++index)
		{
			if( (actual % divisors[index])==0 )
			{
				divided = {true};
				std::cout << words[index] << " ";
			}
		}
		if(!divided)
		{	
			std::cout << actual ;
		}
		std::cout << " ";
	}

	return 0;
}


