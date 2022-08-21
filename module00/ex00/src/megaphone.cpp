#include <iostream>

int	main( int argc, char **argv ) {

	int	i = 1;

	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	while (i  < argc)
	{
		for (int j = 0 ; argv[i][j]; j++)
			std::cout << (char)std::toupper(argv[i][j]);
		i++;
		if (i < argc)
			std::cout << ' ';
	}
	std::cout << std::endl;
	return 0;
}
