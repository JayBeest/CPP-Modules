#include "Zombie.hpp"

void	newChump(std::string name)
{
	Zombie new_zombie(name);
    new_zombie.announce();
}
