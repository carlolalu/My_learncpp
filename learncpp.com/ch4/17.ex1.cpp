#include<iostream>
#include<string>

int main(void)
{
	std::cout << "Please state your complete name: ";
	std::string name {};
	std::getline(std::cin >> std::ws, name);
	
	std::cout << "\nPlease state your age: ";
        int age {};
        std::cin >> age;

	int sum {};
	sum = age + static_cast<int>(name.length());
	std::cout << "\nThe sum of the lenght of your name and your age is : " << sum << '\n';

	
	return 0;
}
