#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void	more_test( void )
{
	Dog		dog("Ken");
	Cat		cat("Stein");
	Animal	animal("Fran");
	Dog		clean_dog;
	Animal	*ptr;
	Cat		*cat_ptr;

	std::cout << animal << dog << cat << std::endl << std::endl;

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
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound();
	meta->makeSound();

	const WrongCat *ptr = (WrongCat *)i;
	ptr->makeSound();

	ptr = (WrongCat *)meta;
	ptr->makeSound();

	delete meta;
	delete i;
}

int main (int argc, char **argv)
{
	if (argc == 2 && std::string(argv[1]) == "-s")
	{
		Animal::makeSilent();
		WrongAnimal::makeSilent();
	}

	std::cout << std::endl << "*** Animal tests ***" << std::endl << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;

	std::cout << std::endl << "*** WrongAnimal tests ***" << std::endl << std::endl;
	wrong_test();
	std::cout << std::endl << "*** More test ***" << std::endl << std::endl;
	more_test();

	return 0;
}
