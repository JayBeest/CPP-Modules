#include <iostream>
#include <iomanip>
#include "Array.tpp"

int main( void ) {

//	int * a = new int();
//	std::cout << *a << std::endl;

	Array<int> b = Array<int>(4);
	for (int i = 0; i < b.size(); i++)
	{
		std::cout << b[i] << std::endl;
	}
	std::cout << std::endl;
	b[0] = 1;
	b[1] = 2;
	b[2] = 3;
	b[3] = 4;
	for (int i = 0; i < b.size(); i++)
	{
		std::cout << std::setw(10) << b[i] << " with mem: " << &b[i] << std::endl;
	}

	Array<int> c = b;
	b[0] = 10000;
	b[1] = 20000;
	b[2] = 30000;
	b[3] = 40000;
	for (int i = 0; i < c.size(); i++)
	{
		std::cout << std::setw(10) << b[i] << " with mem: " << &b[i] << std::endl;
	}
	for (int i = 0; i < c.size(); i++)
	{
		std::cout << std::setw(10) << c[i] << " with mem: " << &c[i] << std::endl;
	}

	return 0;
}
