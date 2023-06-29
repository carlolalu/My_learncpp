#include<iostream>
#include<cmath>

const double gravity = 9.8;

double simulation(double height_init)
{
	double time {};
	double space {height_init};
	double time_to_fall {std::sqrt((height_init*2)/gravity)};

	while(time <= time_to_fall)
	{
		space = height_init - (gravity*time*time)/2;
		std::cout << "\nAfter " << time << "s the ball is at the height of " << space << "m.\n";
		time++;
	}

	std::cout << "\nAfter " << time_to_fall << "s the ball reached the ground.\n";

	return time_to_fall; 
}


int main(void)
{
	std::cout << "You are letting a ball fall off a tower. How tall you imagine the tower to be?\n";
	std::cout << "Enter the height of the tower in meters please: ";
	int height {};
	std::cin >> height;

	simulation(static_cast<double>(height));


	return 0;
}
