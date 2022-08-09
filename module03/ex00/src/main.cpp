#include <iostream>
#include "ClapTrap.hpp"

int main (int argc, char **argv) {

	if (argc == 2 && std::string(argv[1]) == "-s")
	{
		std::cout << std::endl << "Making silent..." << std::endl << std::endl;
		ClapTrap::makeSilent();
	}

	ClapTrap a("Bob");
	ClapTrap b("Eve");

	a.setAttackDamage(3);
	a.attack("Eve");
	b.takeDamage(3);
	a.attack("Eve");
	b.takeDamage(3);
	a.attack("Eve");
	b.takeDamage(3);
	a.attack("Eve");
	b.takeDamage(3);
	a.attack("Eve");
	b.takeDamage(3);
	b.beRepaired(2);
	b.beRepaired(2);
	b.beRepaired(2);
	b.beRepaired(2);
	b.beRepaired(2);
	b.beRepaired(2);
	b.beRepaired(2);
	b.beRepaired(2);
	b.beRepaired(2);
	b.beRepaired(2);
	b.beRepaired(2);
	a.setAttackDamage(12);
	a.attack("Eve");
	b.takeDamage(12);
	a.attack("Eve");
	b.takeDamage(12);
	a.attack("Eve");
	b.takeDamage(12);

	return 0;
}
