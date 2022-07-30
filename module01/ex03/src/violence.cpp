#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

using namespace ::std;

int main ( ){

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
	Atest_human4.attack();
	Atest_human5.attack();
	Atest_human6.attack();
	Atest_human2 = Atest_human1;
	Atest_human1 = HumanA(*Atest_human3);
	Atest_human1.attack();
	Atest_human2.attack();
	Atest_human3->attack();
	Atest_human4.attack();
	Atest_human5.attack();
	Atest_human6.attack();

	delete Atest_human3;


	HumanB	Btest_human1 = HumanB("Bbob");
	HumanB	Btest_human2;
	HumanB	*Btest_human3 = new HumanB("Bben");
	HumanB	Btest_human4 = HumanB("Beve");
	HumanB	Btest_human5 = HumanB(Btest_human4);
	HumanB	Btest_human6 = HumanB(*Btest_human3);

	cout << endl;
	cout << endl;

	Btest_human2.setWeapon(sword);

	Btest_human1.attack();
	Btest_human2.attack();
	Btest_human3->attack();
	Btest_human4.attack();
	Btest_human5.attack();
	Btest_human6.attack();
	Btest_human1.setWeapon(club);
	Btest_human2 = Btest_human1;
	Btest_human1 = HumanB(*Btest_human3);
	Btest_human4 = Btest_human1;
	Btest_human3->setWeapon(club);
	Btest_human1.attack();
	Btest_human2.attack();
	Btest_human3->attack();
	Btest_human4.attack();
	Btest_human5.attack();
	Btest_human6.attack();

	delete Btest_human3;



	return 0;
}
