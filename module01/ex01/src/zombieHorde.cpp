#include "Zombie.hpp"

ClassZombie*	zombieHorde(int N, std::string name)
{
	ClassZombie	*new_horde = new ClassZombie[N];
//	ClassZombie temp = ClassZombie(name);

	for (int i = 0; i < N; i++)
	{
		new_horde[i] = ClassZombie(name);
	}
 	return new_horde;
}