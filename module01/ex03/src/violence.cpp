#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

using namespace ::std;

int main ( ){

	Weapon	club = Weapon("crude spiked club");
	Weapon	sword = Weapon("rusty old sword");
	HumanA	test_human1 = HumanA("bob", club);
	HumanA	test_human2;
	HumanA	*test_human3 = new HumanA("ben", club);
	HumanA	test_human4 = HumanA("eve", sword);
	HumanA	test_human5 = HumanA(test_human4);
	HumanA	test_human6	= HumanA(*test_human3);

	test_human1.attack();
	test_human2.attack();
	test_human3->attack();
	test_human4.attack();
	test_human5.attack();
	test_human6.attack();
	test_human2 = test_human1;
	test_human1 = HumanA(*test_human3);
	test_human1.attack();
	test_human2.attack();
	test_human3->attack();
	test_human4.attack();
	test_human5.attack();
	test_human6.attack();

	delete test_human3;
	return 0;
}
