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
	a->use(2, *a);
	a->use(3, *a);
	a->use(4, *a);
	a->unequip(3);
	a->unequip(1);
	a->use(3, *a);
	a->use(1, *a);
	a->equip(new Ice);
	a->equip(new Ice);
	a->equip(new Ice);
	a->equip(new Ice);


	delete a;
	return 0;
}
