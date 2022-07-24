#include <iostream>
#include "ClassPhonebook.hpp"

using namespace ::std;

int main ( void ){

	Phonebook	book;
	string		cmd;

	book.populatePhonebook();
	while (1)
	{
		cout << "Enter a command: ";
		getline(cin, cmd);
		if (cmd == "ADD")
			book.makeContact();
		else if (cmd == "SEARCH")
			book.searchPhonebook();
		else if (cmd == "EXIT")
			break;
	}
	return 0;
}