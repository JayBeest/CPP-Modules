#include "HumanA.hpp"
#include "HumanB.hpp"

int main (void)
{

	Weapon	club = Weapon("crude spiked club");
	Weapon	sword = Weapon("rusty old sword");
	Weapon	gun = Weapon("jammed colt 42");
    Weapon  default_wep = Weapon();

	HumanA	Atest_human1 = HumanA("bob", club);
	HumanA	*Atest_human2 = new HumanA("ben", gun);
	HumanA	Atest_human3 = HumanA("eve", sword);
	HumanA	Atest_human4 = HumanA("san", default_wep);

	Atest_human1.attack();
	Atest_human2->attack();
	Atest_human3.attack();
	Atest_human4.attack();

    default_wep.setType("Uzi");

	std::cout << std::endl << Atest_human1 << *Atest_human2 << Atest_human3 << Atest_human4 << std::endl;
	delete Atest_human2;
	std::cout << std::endl;

	HumanB	Btest_human1 = HumanB("bob");
	HumanB	*Btest_human2 = new HumanB("ben");
	HumanB	Btest_human3 = HumanB("eve");

	Btest_human2->setWeapon(sword);

	std::cout << Btest_human1 << *Btest_human2 << Btest_human3 << std::endl;
	Btest_human1.setWeapon(club);
	Btest_human3.setWeapon(gun);
	std::cout << Btest_human1 << *Btest_human2 << Btest_human3 << std::endl;

	delete Btest_human2;

	return 0;
}
