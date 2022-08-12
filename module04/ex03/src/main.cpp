#include <iostream>
//#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"

int main (int argc, char **argv ){

	if (argc == 2 && std::string(argv[1]) == "-s")
	{
		Character::makeSilent();
		AMateria::makeSilent();
	}
	ICharacter *sandra = new Character("Sandra");
	ICharacter *alfred = new Character("Alfred");
	ICharacter *test;
//	ICharacter test;

	sandra->equip(new Ice);
	sandra->equip(new Ice);
	sandra->equip(new Ice);
	sandra->equip(new Ice);
	sandra->equip(new Ice);
	sandra->use(0, *alfred);
	sandra->use(1, *alfred);
	sandra->use(2, *alfred);
	sandra->use(3, *alfred);
	sandra->use(4, *alfred);
	sandra->unequip(3);
	sandra->unequip(1);
	sandra->use(3, *alfred);
	sandra->use(1, *alfred);
	test = alfred;
	test->equip(new Ice);
	test->equip(new Ice);
	test->equip(new Ice);
	test->equip(new Ice);

	delete sandra;
	delete alfred;
	return 0;
}
