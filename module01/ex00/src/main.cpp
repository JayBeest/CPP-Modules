#include <iostream>
#include "Zombie.hpp"

int main ( )
{
	Zombie	*real_z = newZombie("Brutus");
	Zombie	chump = newChump("Dork");

	delete real_z;
	return 1;
}
