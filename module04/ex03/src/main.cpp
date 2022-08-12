#include <iostream>
#include "nullptr_compat.h"
//#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Fire.hpp"
#include "MateriaSource.hpp"

void	test_materia_source()
{
	AMateria *				temp = nullptr;
	IMateriaSource * const	mat_source = new MateriaSource();
	ICharacter * const		bas = new Character("Bas");
	ICharacter * const		eve = new Character("Eve");

	mat_source->learnMateria(new Ice);
	mat_source->learnMateria(new Cure);
	mat_source->learnMateria(new Fire);
	temp = mat_source->createMateria("ice");
	if (temp)
		bas->equip(temp);
	temp = mat_source->createMateria("fire");
	if (temp)
		bas->equip(temp);
	temp = mat_source->createMateria("cure");
	if (temp)
		bas->equip(temp);
	bas->use(0, *eve);
	bas->use(1, *eve);
	bas->use(2, *eve);

	delete mat_source;
	delete bas;
	delete eve;
}

int main2 (int argc, char **argv ){

	if (argc == 2 && std::string(argv[1]) == "-s")
	{
		Character::makeSilent();
		AMateria::makeSilent();
	}
	ICharacter * const sandra = new Character("Sandra");
	ICharacter * const alfred = new Character("Alfred");
	ICharacter * test;
//	ICharacter test;

	std::cout << std::endl << std::endl << "<** MAIN 2 **>" << std::endl << std::endl;

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

int main (int argc, char **argv ){

	if (argc == 2 && std::string(argv[1]) == "-s")
	{
		Character::makeSilent();
		AMateria::makeSilent();
	}

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return main2(argc, argv);
}
