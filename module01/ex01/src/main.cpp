#include <iostream>
#include <sstream>
#include "Zombie.hpp"

int main (int argc, char **argv)
{
	int					zombie_amount = 50;
	std::stringstream	s_stream;

	if (argc > 1)
	{
		s_stream << argv[1];
		s_stream >> zombie_amount;
		if (zombie_amount < 0)
		{
			std::cout << " how many zombies?!" << std::endl;
			return 1;
		}
	}
	Zombie	*horde = zombieHorde(zombie_amount, "Brutus");
	for (int i = 0; i < zombie_amount; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}
