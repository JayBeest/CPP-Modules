#include <iostream>
#include "FragTrap.hpp"

int main (int argc, char **argv) {

	if (argc == 2 && std::string(argv[1]) == "-s")
	{
		std::cout << std::endl << "Making silent..." << std::endl << std::endl;
		ClapTrap::makeSilent();
	}

	FragTrap a("Bob");
	FragTrap b("Aaf");
	FragTrap c;

	a.attack("Aaf");
	b.takeDamage(30);
	a.attack("Aaf");
	b.takeDamage(30);
	a.attack("Aaf");
	b.takeDamage(30);

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
	b.takeDamage(30);
	b.highFivesGuys();

	a.attack("Aaf");
	b.takeDamage(30);
	a.attack("Aaf");
	b.takeDamage(30);
	b.beRepaired(300);
	b.attack("Ben");
	b.highFivesGuys();

	return 0;
}
