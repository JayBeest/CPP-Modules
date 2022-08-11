#include <iostream>
#include <sstream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void	test( void )
{
//	Animal::makeSilent();
//	Cat::makeSilent();
//	Dog::makeSilent();

	Animal	animal("Fran");
	Cat		cat("Stein");
	Dog		dog("Ken");
	Dog		clean_dog;
	Animal	*ptr;
	Cat		*cat_ptr;

	std::cout << std::endl << animal << dog << cat << std::endl << std::endl;

	ptr = &animal;
	std::cout << *ptr << ": ";
	ptr->makeSound();
	ptr = &dog;
	std::cout << *ptr << ": ";
	ptr->makeSound();
	ptr = &cat;
	std::cout << *ptr << ": ";
	ptr->makeSound();

	cat_ptr = (Cat *)&clean_dog;
	std::cout << *cat_ptr << ": ";
	cat_ptr->makeSound();

}

void	wrong_test( void )
{
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	meta->makeSound();

	const WrongCat *ptr = (WrongCat *)i;
	ptr->makeSound();

	ptr = (WrongCat *)meta;
	ptr->makeSound();

	delete meta;
	delete i;
}

void	print_brain(Cat & cat)
{
	for (int i = 0; i < MAX_IDEAS; i++)
	{
		if (cat.accessBrain().getIdea(i).empty())
			return;
		std::cout << cat << "'s brain(" << i << "): " << cat.accessBrain().getIdea(i) << std::endl;
	}
}

void	test_brain()
{
	Cat	cat_a("cat_a");
	Cat cat_b("cat_b");

	print_brain(cat_a);
	std::cout << std::endl;
	for (int i = 0; i < MAX_IDEAS/2; i++)
	{
		std::stringstream	s_stream;

		s_stream << i;
		cat_a.accessBrain().addIdea("ideetje: " + s_stream.str());
	}
	print_brain(cat_a);
	std::cout << std::endl;

	print_brain(cat_b);
	std::cout << std::endl;
	cat_b = cat_a;
	print_brain(cat_b);
	std::cout << std::endl;
}

int main (int argc, char **argv)
{
	if (argc == 2 && std::string(argv[1]) == "-s")
	{
		Animal::makeSilent();
		WrongAnimal::makeSilent();
	}
//	const Animal* meta = new Animal();
//	const Animal* j = new Dog();
//	const Animal* i = new Cat();
//	std::cout << j->getType() << " " << std::endl;
//	std::cout << i->getType() << " " << std::endl;
//	i->makeSound(); //will output the cat sound!
//	j->makeSound();
//	meta->makeSound();
//	delete meta;
//	delete i;
//	delete j;
//
//	std::cout << std::endl << "Starting test:" << std::endl << std::endl;
//	test();
//	std::cout << std::endl << "Starting wrong_test:" << std::endl << std::endl;
//	wrong_test();

//	const Animal* j = new Dog();
	const Animal*	i = new Cat();
	Cat				j;
	Animal			k;

	std::cout << j << ": ";
	j.makeSound();
	j = *(Cat *)i;
	std::cout << j << ": ";
	j.makeSound();
	std::cout << k << ": ";
	k.makeSound();
	delete i;

	test_brain();

	return 0;
}
