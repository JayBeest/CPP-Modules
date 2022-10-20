#include <sstream>
#include "Cat.hpp"
#include "Dog.hpp"

void	print_brain(Cat & cat)
{
	for (int i = 0; i < MAX_IDEAS; i++)
	{
		if (cat.accessBrain().getIdea(i).empty())
			return;
		std::cout << cat << "'s brain(" << i << "): " << cat.accessBrain().getIdea(i) << " mem-loc: " << cat.accessBrain().getIdeaLoc(i) << std::endl;
	}
}

void	test_brain()
{
	Cat	*cat_a = new Cat("cat_a");
	Cat *cat_b = new Cat("cat_b");

	print_brain(*cat_a);
	std::cout << std::endl;
	for (int i = 1; i < MAX_IDEAS; i++)
	{
		std::stringstream	s_stream;

		s_stream << i;
		cat_a->accessBrain().addIdea("ideetje: " + s_stream.str());
	}
	print_brain(*cat_a);
	std::cout << std::endl;
	std::cout << std::endl << "*** Printing cat_b brain OG ***" << std::endl << std::endl;
	print_brain(*cat_b);
	std::cout << std::endl;

	std::cout << "*** Printing cat_b brain after cat_b->brain = cat_a->brain ***" << std::endl << std::endl;
	cat_b->accessBrain() = cat_a->accessBrain();
	print_brain(*cat_b);

	std::cout << std::endl << "*** Printing cat_b brain after cat_b = cat_a ***" << std::endl << std::endl;
	*cat_b = *cat_a;
	print_brain(*cat_b);


	std::cout << std::endl << "*** Printing cat_b brain after del cat_a ***" << std::endl << std::endl;
	delete cat_a;
	std::cout << cat_b->accessBrain() << std::endl;
	delete cat_b;
}

void	subjectMain( ) {

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

}
int main(int argc, char **argv)
{
	if (argc == 2 && std::string(argv[1]) == "-s")
	{
		std::cout << "Silencing [Animal].. to silence [Brain] as well use -s2" << std::endl;
		Animal::makeSilent();
	}
	else if (argc == 2 && std::string(argv[1]) == "-s2")
	{
		Animal::makeSilent();
		Brain::makeSilent();
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

	std::cout << std::endl << "directprintofbrain:" << j.accessBrain() << std::endl;

	test_brain();

	subjectMain();

	return 0;
}
