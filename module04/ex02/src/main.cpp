#include <iostream>
#include <sstream>
#include "Cat.hpp"
#include "Dog.hpp"

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
	std::cout << cat_a.accessBrain() << std::endl;
}

int main(int argc, char **argv)
{
	if (argc == 2 && std::string(argv[1]) == "-s")
		Animal::makeSilent();

	const Animal*	i = new Cat();
	const Animal * ptr;
	Cat				j;

	std::cout << j << ": ";
	j.makeSound();

	ptr = i;
	std::cout << std::endl << "pointerstuff: ---> " << *ptr << ": ";
	ptr->makeSound();
	std::cout << std::endl;

	j = *(Cat *)i;
	std::cout << j << ": ";
	j.makeSound();
	delete i;

	test_brain();

	std::cout << std::endl << "directprintofbrain:" << j.accessBrain() << std::endl;
	return 0;
}

//int main(void)
//{
//	const Animal* j = new Dog();
//	const Animal* i = new Cat();
//	delete j;//should not create a leak
//	delete i;
//}
