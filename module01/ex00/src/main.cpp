#include <iostream>
#include "Zombie.hpp"

using namespace ::std;

int main ( )
{
	ClassZombie	*real_z = newZombie("Brutus");
	ClassZombie	chump = newChump("Dork");

	delete real_z;
	return 1;
}
