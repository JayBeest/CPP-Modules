#include <iostream>
#include "ClassPhonebook.hpp"

using namespace ::std;

int main ( ){

	Phonebook	book(PROMPT);
	string		cmd;

	while (true)
	{
		cmd = book.readInput(PROMPT);
		if (cmd == "ADD")
			book.makeContact();
		else if (cmd == "SEARCH" || cmd == "s")
			book.searchPhonebook( );
		else if (cmd == "POP" || cmd == "p")
			book.populatePhonebook( );
		else if (cmd == "EXIT" || cmd == "e")
			break;
		else
			book.printUsage();
	}

	return 0;
}