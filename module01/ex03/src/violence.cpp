#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

using namespace ::std;

int main (int argc, char **argv)
{
	if (argc > 1 && std::string(argv[1]) == "-v")
	{
		HumanA::verbose = true;
		HumanB::verbose = true;
	}
	Weapon	club = Weapon("crude spiked club");
	Weapon	sword = Weapon("rusty old sword");

	HumanA	Atest_human1 = HumanA("bob", club);
	HumanA	Atest_human2;
	HumanA	*Atest_human3 = new HumanA("ben", club);
	HumanA	Atest_human4 = HumanA("eve", sword);
	HumanA	Atest_human5 = HumanA(Atest_human4);
	HumanA	Atest_human6	= HumanA(*Atest_human3);


	Atest_human1.attack();
	Atest_human2.attack();
	Atest_human3->attack();
	cout << Atest_human4;
	cout << Atest_human5;
	cout << Atest_human6;
	Atest_human2 = Atest_human1;
	Atest_human1 = HumanA(*Atest_human3);
	cout << Atest_human1 << Atest_human2 << *Atest_human3 << Atest_human4 << Atest_human5 << Atest_human6;

	delete Atest_human3;

	cout << endl << endl;

	HumanB	Btest_human1 = HumanB("bob");
	HumanB	Btest_human2;
	HumanB	*Btest_human3 = new HumanB("ben");
	HumanB	Btest_human4 = HumanB("eve");
	HumanB	Btest_human5 = HumanB(Btest_human4);
	HumanB	Btest_human6 = HumanB(*Btest_human3);


	Btest_human2.setWeapon(sword);

	cout << Btest_human1 << Btest_human2 << *Btest_human3 << Btest_human4 << Btest_human5 << Btest_human6;
	Btest_human1.setWeapon(club);
	Btest_human2 = Btest_human1;
	Btest_human1 = HumanB(*Btest_human3);
	Btest_human4 = Btest_human1;
	Btest_human3->setWeapon(club);
	cout << Btest_human1 << Btest_human2 << *Btest_human3 << Btest_human4 << Btest_human5 << Btest_human6;

	delete Btest_human3;

	return 0;
}
