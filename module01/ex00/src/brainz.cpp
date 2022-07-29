#include <iostream>
#include "Zombie.hpp"

using namespace ::std;

int main ( ){

	ClassZombie	test1(6);
	ClassZombie	test2;

	cout << test2.getVars() << endl;
	cout << test2.getNb_ClassZombie_created() << endl;

	test2 = test1;

	cout << test2.getVars() << endl;
	cout << test2.getNb_ClassZombie_created() << endl;

	return 0;
}
