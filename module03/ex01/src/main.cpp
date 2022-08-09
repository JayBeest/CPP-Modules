#include <iostream>
//#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main (int argc, char **argv) {

	if (argc == 2 && std::string(argv[1]) == "-s")
	{
		std::cout << std::endl << "Making silent..." << std::endl << std::endl;
		ClapTrap::makeSilent();
	}

	ScavTrap a("Ben");
	ScavTrap b("Aaf");
	ScavTrap c;

	a.attack("Aaf");
	b.takeDamage(20);
	a.attack("Aaf");
	b.takeDamage(20);
	a.attack("Aaf");
	b.takeDamage(20);
	a.attack("Aaf");
	b.takeDamage(20);

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

	a.attack("Aaf");
	b.takeDamage(20);
	a.attack("Aaf");
	b.takeDamage(20);
	b.guardGate();

	a.attack("Aaf");
	b.takeDamage(20);
	a.attack("Aaf");
	b.takeDamage(20);
	b.beRepaired(200);
	b.attack("Ben");
	b.guardGate();

	return 0;
}
