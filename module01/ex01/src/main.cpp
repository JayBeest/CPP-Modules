#include "Zombie.hpp"

int main (void) {

	int     zombie_amount = 50;

	Zombie	*horde = zombieHorde(zombie_amount, "Brutus");
	for (int i = 0; i < zombie_amount; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}
