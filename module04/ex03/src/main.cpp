#include <iostream>
//#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"

int main ( ){

	ICharacter *a = new Character("test_char");

	a->equip(new Ice);
	a->equip(new Ice);
	a->equip(new Ice);
	a->equip(new Ice);
	a->equip(new Ice);
	a->use(0, *a);
	a->use(1, *a);

	return 0;
}
