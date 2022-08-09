#include <iostream>
#include "DiamondTrap.hpp"

void	stats(const ClapTrap & c_trap)
{
	std::cout << std::endl << "< " << c_trap.getName() << "'s stats >" << std::endl;
	std::cout << "Hit Points:    " << c_trap.getHitPoints() << std::endl;
	std::cout << "Energy points: " << c_trap.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << c_trap.getAttackDamage() << std::endl << std::endl;
}

int main (int argc, char **argv) {

	if (argc == 2 && std::string(argv[1]) == "-s")
	{
		std::cout << std::endl << "Making silent..." << std::endl << std::endl;
		ClapTrap::makeSilent();
	}

//	FragTrap a("Bob");
//	FragTrap b("Aaf");
//	FragTrap c;
//
//	a.attack("Aaf");
//	b.takeDamage(30);
//	a.attack("Aaf");
//	b.takeDamage(30);
//	a.attack("Aaf");
//	b.takeDamage(30);
//
//	b.beRepaired(2);
//	b.beRepaired(2);
//	b.beRepaired(2);
//	b.beRepaired(2);
//	b.beRepaired(2);
//	b.beRepaired(2);
//	b.beRepaired(2);
//	b.beRepaired(2);
//	b.beRepaired(2);
//	b.beRepaired(2);
//	b.beRepaired(2);
//
//	a.attack("Aaf");
//	b.takeDamage(30);
//	b.highFivesGuys();
//
//	a.attack("Aaf");
//	b.takeDamage(30);
//	a.attack("Aaf");
//	b.takeDamage(30);
//	b.beRepaired(300);
//	b.attack("Ben");
//	b.highFivesGuys();

	DiamondTrap d("Weirdo");
	d.attack("Remi");
	d.guardGate();
	d.highFivesGuys();
	d.whoAmI();
	stats(d);


	return 0;
}
