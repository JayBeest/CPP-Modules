#include <iostream>
//#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"

int main ( ){

	ICharacter *a = new Character("test_char");

	a->equip(new Ice);

	return 0;
}
