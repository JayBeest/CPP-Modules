#include <iostream>
#include "Array.tpp"

int main( void ) {

//	int * a = new int();
//	std::cout << *a << std::endl;

	Array<int> b = Array<int>(12);
	for (int i = 0; i < b.size(); i++)
	{
		std::cout << b[i] << std::endl;
	}
	std::cout << std::endl;
	b[3] = 4;
	b[6] = 3423;
	b[4] = 10000;
	b[9] = 3;
	for (int i = 0; i < b.size(); i++)
	{
		std::cout << b[i] << std::endl;
	}

	return 0;
}
