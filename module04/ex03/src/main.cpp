#include <iostream>
//#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Fire.hpp"
#include "MateriaSource.hpp"

void	test_materia_source()
{
	IMateriaSource * const	mat_source = new MateriaSource();
	ICharacter * const		bas = new Character("Bas");
	ICharacter * const		eve = new Character("Eve");

	mat_source->learnMateria(new Ice);
	mat_source->learnMateria(new Cure);
	mat_source->learnMateria(new Fire);
	bas->equip(mat_source->createMateria("ice")->clone());
	bas->equip(mat_source->createMateria("fire")->clone());
	bas->equip(mat_source->createMateria("cure")->clone());
	bas->use(0, *eve);
	bas->use(1, *eve);
	bas->use(2, *eve);

	delete mat_source;
	delete bas;
	delete eve;
}

int main (int argc, char **argv ){

	if (argc == 2 && std::string(argv[1]) == "-s")
	{
		Character::makeSilent();
		AMateria::makeSilent();
	}
	ICharacter * const sandra = new Character("Sandra");
	ICharacter * const alfred = new Character("Alfred");
	ICharacter * test;
//	ICharacter test;

	sandra->equip(new Fire);
	sandra->equip(new Ice);
	sandra->equip(new Ice);
	sandra->equip(new Fire);
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
	std::cout << std::endl << "Test starts:" << std::endl << std::endl;
	test = sandra;
	test->equip(new Cure);
	test->equip(new Cure);
	test->equip(new Cure);
	test->use(0, *alfred);
	test->use(1, *alfred);
	test->use(2, *alfred);
	test->use(3, *alfred);
	test->use(4, *alfred);

	delete sandra;
	delete alfred;

	std::cout << std::endl << "Starting (I)Materiasource tests:" << std::endl << std::endl;
	test_materia_source();

	return 0;
}
