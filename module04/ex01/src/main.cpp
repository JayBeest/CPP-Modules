#include <iostream>
#include <sstream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

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
	for (int i = 0; i < MAX_IDEAS*2; i++)
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
