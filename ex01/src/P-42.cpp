#include <iostream>
#include "ClassPhonebook.hpp"

using namespace ::std;

int main ( ){

	Phonebook	book("root@Z-42:/# ");
	string		cmd;
	int			count = 0;

	while (1)
	{
		cout << book.getPrompt( );
		getline(cin, cmd);
		if (cmd.empty())
			(void)cmd;
		else if (cmd == "ADD")
			book.makeContact( );
		else if (cmd == "SEARCH" || cmd == "s")
			book.searchPhonebook( );
		else if (cmd == "POP" || cmd == "p")
			book.populatePhonebook( );
		else if (cmd == "EXIT" || cmd == "e")
			break;
		else
		{
			cout << endl
				 << "Usage: ADD - add a contact" << endl
				 << "       SEARCH - search the Z-42 phonebook" << endl
				 << "       EXIT - exit" << endl
				 << endl;
			count = 0;
		}
		count++;
		if (count > 6)
		{
			cout << endl
				<< "Usage: ADD - add a contact" << endl
				<< "       SEARCH - search the Z-42 phonebook" << endl
				<< "       EXIT - exit" << endl
				<< endl;
			count = 0;
		}
	}
	return 0;
}