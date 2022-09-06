#include "Harl.hpp"

int main (int argc, char **argv ){

	if (argc != 2)
	{
		std::cout << "Harl will only take one argument" << std::endl;
		return 1;
	}
	Harl().complain(std::string(argv[1]));
	return 0;
}
