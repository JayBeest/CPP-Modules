#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

using namespace ::std;

int main ( ){

	Weapon	club = Weapon("crude spiked club");
	HumanA	test_human1 = HumanA("bob", club);
	HumanA	test_human2;

	test_human1.attack();
	test_human2.attack();
	test_human2 = test_human1;
	test_human1.attack();
	test_human2.attack();

	return 0;
}
