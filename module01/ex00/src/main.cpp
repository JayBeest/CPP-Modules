#include <iostream>
#include "Zombie.hpp"

int main ( )
{
	Zombie	*real_z = newZombie("Brutus");
    real_z->announce();
	delete real_z;
	newChump("Dork");
	return 1;
}
