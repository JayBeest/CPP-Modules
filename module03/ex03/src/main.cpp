#include <iostream>
#include "DiamondTrap.hpp"

void	clapTest(void)
{
	std::cout << "*** ClapTrap tests ***" << std::endl << std::endl;

	ClapTrap a("Bob");
	ClapTrap b("Eve");

	a.setAttackDamage(3);
	a.attack("Eve");
	b.takeDamage(a.getAttackDamage());
	a.attack("Eve");
	b.takeDamage(a.getAttackDamage());
	a.attack("Eve");
	b.takeDamage(a.getAttackDamage());

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
	b.takeDamage(a.getAttackDamage());
	a.attack("Eve");
	b.takeDamage(a.getAttackDamage());
	a.attack("Eve");
	b.takeDamage(a.getAttackDamage());
}

void	scavTest(void)
{
	std::cout << "*** ScavTrap tests ***" << std::endl << std::endl;

	ScavTrap a("Ben");
	ScavTrap b("Aaf");
	ScavTrap c;

	a.attack("Aaf");
	b.takeDamage(a.getAttackDamage());
	a.attack("Aaf");
	b.takeDamage(a.getAttackDamage());
	a.attack("Aaf");
	b.takeDamage(a.getAttackDamage());
	a.attack("Aaf");
	b.takeDamage(a.getAttackDamage());

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
	b.takeDamage(a.getAttackDamage());
	a.attack("Aaf");
	b.takeDamage(a.getAttackDamage());
	b.guardGate();

	a.attack("Aaf");
	b.takeDamage(a.getAttackDamage());
	a.attack("Aaf");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(2);
	b.attack("Ben");
	b.guardGate();
}

void	fragTest(void)
{

	std::cout << "*** FragTrap tests ***" << std::endl << std::endl;

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
}

void	stats(const ClapTrap & c_trap)
{
	std::cout << std::endl << "< " << c_trap.getName() << "'s stats >" << std::endl;
	std::cout << "Hit Points:    " << c_trap.getHitPoints() << std::endl;
	std::cout << "Energy points: " << c_trap.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << c_trap.getAttackDamage() << std::endl << std::endl;
}

void	diamondTest() {

	std::cout << "*** Diamond Trap tests ***" << std::endl;

	std::cout << std::endl;
	DiamondTrap d("Weirdo");
	std::cout << std::endl;
	d.attack("Remi");
	d.guardGate();
	d.highFivesGuys();
	d.whoAmI();
	stats(d);
}

int main (int argc, char **argv) {

	if (argc == 2 && std::string(argv[1]) == "-s")
	{
		std::cout << std::endl << "Making silent..." << std::endl << std::endl;
		ClapTrap::makeSilent();
	}

	diamondTest();

	fragTest();
	std::cout << std::endl;
	scavTest();
	std::cout << std::endl;
	clapTest();

	return 0;
}
