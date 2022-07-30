#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

using namespace ::std;

int main ( ){

	Weapon	club = Weapon("crude spiked club");
	HumanA	test_human1 = HumanA("bob", club);

	return 0;
}
