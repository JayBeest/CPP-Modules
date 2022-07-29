#include <iostream>
#include "Zombie.hpp"

using namespace ::std;

int main ( )
{
	int	zombie_amount = 10;
	ClassZombie	*horde = zombieHorde(zombie_amount, "Bas");
	for (int i = 0; i < zombie_amount; i++)
		horde->announce();
//	for (int i = 0; i < zombie_amount - 1; i++)
//		delete &(horde[i]);
	delete[] horde;
//	system("leaks moar_brainz");
	return 1;
}
