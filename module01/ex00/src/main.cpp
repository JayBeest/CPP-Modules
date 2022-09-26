#include "Zombie.hpp"

int main ( )
{
	Zombie	*real_z = newZombie("Brutus");
    real_z->announce();
	delete real_z;
	randomChump("Dork");
	return 0;
}
