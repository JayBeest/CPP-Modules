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
	ICharacter *a = new Character("test_char");

	a->equip(new Ice);
	a->equip(new Ice);
	a->equip(new Ice);
	a->equip(new Ice);
	a->equip(new Ice);
	a->use(0, *a);
	a->use(1, *a);

	delete a;
	return 0;
}
