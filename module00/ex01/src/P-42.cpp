#include <iostream>
#include "ClassPhonebook.hpp"

int main ( ){

	Phonebook	book(PROMPT);
	std::string	cmd;

	while (true)
	{
		cmd = book.readInput(PROMPT);
		if (cmd == "ADD")
			book.makeContact();
		else if (cmd == "SEARCH")
			book.searchPhonebook( );
		else if (cmd == "EXIT")
			break;
		else
			book.printUsage();
	}
	return 0;
}

//int main ( ){
//
//	Phonebook	book(PROMPT);
//	std::string	cmd;
//
//	while (true)
//	{
//		cmd = book.readInput(PROMPT);
//		if (cmd == "ADD" || cmd == "a")
//			book.makeContact();
//		else if (cmd == "SEARCH" || cmd == "s")
//			book.searchPhonebook( );
//		else if (cmd == "POP" || cmd == "p")
//			book.populatePhonebook( );
//		else if (cmd == "EXIT" || cmd == "e")
//			break;
//		else
//			book.printUsage();
//	}
//
//	return 0;
//}
