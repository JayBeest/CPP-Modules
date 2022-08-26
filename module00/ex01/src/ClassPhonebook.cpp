#include <iomanip>
#include <sstream>
#include "ClassPhonebook.hpp"

bool	Phonebook::empty( ) const {

	return this->_empty;
}

std::string	Phonebook::get_prompt( ) const {

	return this->_prompt;
}

Phonebook::Phonebook( const std::string & prompt )
		: _empty(true), _prompt(prompt), _contacts() {

	std::cout << std::endl << std::setw(24) << "Zapp!" << std::endl << std::endl;
	std::cout << "This is the crappy P-42 phonebook operator" << std::endl;
	std::cout << "go ahead.." << std::endl;
	printUsage();
}

Phonebook::Phonebook( Phonebook const & other ) {

	*this = other;
}

Phonebook::~Phonebook( ) {

	std::cout << std::endl << "..so sweet" << std::endl;
	std::cout << "This was the crappy P-42 phonebook operator" << std::endl;
	std::cout  << std::endl << std::setw(25) << "Zapp!" <<  std::endl << std::endl;
}

Phonebook&	Phonebook::operator=( Phonebook const & rhs ) {

	if (this != &rhs)
	{
		this->_prompt = rhs.get_prompt();
		if (!rhs.empty())
		{
			for (int i = 0; i < Contact::get_nbContacts(); i++)
				this->_contacts[i] = rhs._getContact(i);
			this->_empty = false;
		}
	}
	return *this;
}

std::string	Phonebook::readInput( std::string prompt ) const {

	std::string			buffer;
	int				count = 0;
	std::stringstream	out_nb_contacts;

	if (Contact::get_nbContacts() <= MAX_CONTACTS)
		out_nb_contacts << Contact::get_nbContacts();
	else
		out_nb_contacts << MAX_CONTACTS;
	while (buffer.empty())
	{
		std::cout << prompt;
		getline(std::cin, buffer);
		if (prompt == "Input phone number: "
			&& buffer.find_first_not_of("1234567890") != std::string::npos)
			buffer.clear();
		if (buffer.empty())
			count++;
		if (count > 6)
		{
			if (prompt == std::string(PROMPT))
				printUsage();
			else if(prompt == this->_prompt + "Input index: ")
				prompt += "[1-" + out_nb_contacts.str() + "] ";
			else if(prompt != "Input first name: " &&
					prompt != "Input last name: " &&
					prompt != "Input nickname: " &&
					prompt != "Input phone number: " &&
					prompt != "Input dark secret:")
				this->_printSearch();
			count = 0;
		}
	}
	return buffer;
}

void	Phonebook::printUsage( ) const {

	std::cout << std::endl
			  << "Usage: ADD - add a contact" << std::endl
			  << "       SEARCH - search the Z-42 phonebook" << std::endl
			  << "       EXIT - exit" << std::endl
			  << std::endl;
}

void	Phonebook::searchPhonebook( ) const {

	std::string			prompt = "Input index: ";
	std::string			cmd;
	std::stringstream	ss_nb_contacts;
	int 			i;

	if (Contact::get_nbContacts() == 0)
	{
		std::cout << std::endl << "No contacts present in T-42 phonebook" << std::endl << std::endl;
		return;
	}
	this->_printSearch();
	if (Contact::get_nbContacts() <= MAX_CONTACTS)
		ss_nb_contacts << Contact::get_nbContacts( );
	else
		ss_nb_contacts << MAX_CONTACTS;
	while (true)
	{
		cmd = readInput(this->_prompt + prompt);
		if (!isdigit(cmd[0]) || cmd.size() > 1)
			prompt = "Input index: [1-" + ss_nb_contacts.str() + "] ";
		else
		{
			i = atoi(cmd.c_str());   /// strtol!!!
			if (i > 0 && i <= (int)Contact::get_nbContacts() && i <= MAX_CONTACTS)
			{
				this->_printContact(this->_getContact(i - 1));
				return;
			}
			prompt = "Input index: [1-" + ss_nb_contacts.str() + "] ";
		}
	}
}

void		Phonebook::makeContact( ) {

	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_nb;
	std::string	dark_secret;

	first_name = readInput("Input first name: ");
	last_name = readInput("Input last name: ");
	nick_name = readInput("Input nickname: ");
	phone_nb = readInput("Input phone number: ");
	dark_secret = readInput("Input dark secret: ");
	this->_addContact(Contact(first_name, last_name, nick_name, phone_nb, dark_secret));
}

void	Phonebook::populatePhonebook( ) {

	this->_addContact(Contact("Jay Bart", "Cornelisse", "JayBeest", "06xxxxxx57", "jbjbjbjbjbjbjb"));
	this->_addContact(Contact("Dwayne", "Cornelisse", "Dwappa", "06xxxxxx43", "dddddddddddddddddd"));
	this->_addContact(Contact("Frans Bart", "Cornelisse", "FB", "06xxxxxx81", "fbfbfbfbfbfbfbfb"));
	this->_addContact(Contact("Pauline", "de Vries", "Ploon", "06xxxxxx12", "PPPPPPPPPPPPPPPPPP"));
	this->_addContact(Contact("Mary Love", "Cornelisse", "ML", "06xxxxxx53", "mlmlmlmlmlmlmlmlmlml"));
	this->_addContact(Contact("Michael", "Jackson", "MJ", "06xxxxxx91", "ouw!"));
	this->_addContact(Contact("Max", "Verstappen", "SuperMax", "06xxxxxx33", "maxmaxmaxmaxmax"));
	this->_addContact(Contact("Lewis", "Hammilton", "Hammertime", "06xxxxxx45", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Pretium quam vulputate dignissim suspendisse in. Massa tincidunt dui ut ornare lectus sit. Tellus in metus vulputate eu. Sagittis purus sit amet volutpat consequat mauris nunc congue nisi. Eleifend quam adipiscing vitae proin sagittis nisl. Interdum velit laoreet id donec ultrices. In hac habitasse platea dictumst vestibulum rhoncus. Sit amet nisl suscipit adipiscing bibendum. Proin libero nunc consequat interdum. At elementum eu facilisis sed odio morbi.\n"
																				"\n"
																				"Fermentum iaculis eu non diam phasellus vestibulum lorem. At consectetur lorem donec massa. Feugiat nibh sed pulvinar proin gravida. Fames ac turpis egestas sed tempus urna. Facilisi cras fermentum odio eu feugiat pretium. Arcu vitae elementum curabitur vitae nunc sed velit dignissim. Volutpat ac tincidunt vitae semper quis. Quis risus sed vulputate odio ut enim blandit volutpat maecenas. Ante in nibh mauris cursus mattis molestie. Nisl rhoncus mattis rhoncus urna neque viverra justo. Nec dui nunc mattis enim ut. Sapien faucibus et molestie ac feugiat. Justo nec ultrices dui sapien eget. Vulputate enim nulla aliquet porttitor lacus. Laoreet id donec ultrices tincidunt arcu non sodales. Ullamcorper eget nulla facilisi etiam dignissim diam quis. Ut eu sem integer vitae justo eget magna. Amet porttitor eget dolor morbi. Risus sed vulputate odio ut enim blandit volutpat. In iaculis nunc sed augue lacus viverra vitae congue eu.\n"
																				"\n"
																				"Eget nunc scelerisque viverra mauris in aliquam. In pellentesque massa placerat duis ultricies lacus. Venenatis a condimentum vitae sapien pellentesque habitant morbi tristique senectus. Aliquam malesuada bibendum arcu vitae elementum curabitur vitae nunc sed. Commodo sed egestas egestas fringilla phasellus faucibus. Est placerat in egestas erat imperdiet sed euismod nisi. Consectetur lorem donec massa sapien faucibus et molestie ac feugiat. Aliquam sem et tortor consequat. Rutrum quisque non tellus orci ac auctor augue. Non curabitur gravida arcu ac tortor dignissim convallis aenean.\n"
																				"\n"
																				"Dictumst quisque sagittis purus sit amet volutpat consequat mauris nunc. In hendrerit gravida rutrum quisque. Sed vulputate odio ut enim. Vitae et leo duis ut diam. Tortor at auctor urna nunc id cursus metus. Leo in vitae turpis massa sed elementum. In eu mi bibendum neque. At ultrices mi tempus imperdiet nulla malesuada pellentesque. Sodales neque sodales ut etiam sit amet nisl purus in. Neque aliquam vestibulum morbi blandit cursus. Sed ullamcorper morbi tincidunt ornare massa eget egestas. Malesuada nunc vel risus commodo viverra maecenas accumsan lacus vel. Suspendisse ultrices gravida dictum fusce ut placerat orci. Nec ullamcorper sit amet risus nullam eget felis eget. Diam vel quam elementum pulvinar etiam non quam. Urna duis convallis convallis tellus. Convallis posuere morbi leo urna. Posuere urna nec tincidunt praesent semper feugiat nibh sed. Enim lobortis scelerisque fermentum dui.\n"
																				"\n"
																				"Sapien faucibus et molestie ac feugiat sed lectus vestibulum. Massa vitae tortor condimentum lacinia quis vel eros. Turpis egestas pretium aenean pharetra. Quis lectus nulla at volutpat diam ut venenatis. Arcu bibendum at varius vel pharetra vel turpis nunc eget. Senectus et netus et malesuada. Nec ullamcorper sit amet risus nullam eget. Cras adipiscing enim eu turpis egestas pretium aenean. Et sollicitudin ac orci phasellus egestas tellus rutrum tellus. Id cursus metus aliquam eleifend mi. Morbi tincidunt augue interdum velit euismod in pellentesque. Dui accumsan sit amet nulla facilisi morbi tempus. In ornare quam viverra orci. Urna condimentum mattis pellentesque id nibh. Accumsan in nisl nisi scelerisque.\n"
																				"\n"
																				"Adipiscing enim eu turpis egestas pretium. In fermentum posuere urna nec tincidunt praesent. Id cursus metus aliquam eleifend mi in nulla posuere sollicitudin. Egestas diam in arcu cursus euismod quis. Ullamcorper morbi tincidunt ornare massa eget egestas purus. Venenatis cras sed felis eget velit aliquet sagittis id consectetur. Metus aliquam eleifend mi in nulla posuere sollicitudin aliquam. Ornare arcu odio ut sem nulla pharetra diam. Porta non pulvinar neque laoreet suspendisse interdum consectetur. Urna neque viverra justo nec. Tincidunt vitae semper quis lectus nulla at. Risus quis varius quam quisque. Sed id semper risus in hendrerit gravida rutrum quisque. Mauris rhoncus aenean vel elit.\n"
																				"\n"
																				"Vulputate dignissim suspendisse in est ante in nibh mauris cursus. Ipsum a arcu cursus vitae congue mauris rhoncus. Aliquet sagittis id consectetur purus ut faucibus pulvinar elementum. Risus feugiat in ante metus dictum at tempor commodo. Velit laoreet id donec ultrices. Tristique et egestas quis ipsum suspendisse ultrices gravida dictum. Nisl suscipit adipiscing bibendum est. Id neque aliquam vestibulum morbi blandit cursus risus at. Tempor orci dapibus ultrices in iaculis. Aliquet bibendum enim facilisis gravida neque convallis a cras semper. Aliquet bibendum enim facilisis gravida neque convallis a cras semper. Ut lectus arcu bibendum at varius vel pharetra. Feugiat nisl pretium fusce id velit ut tortor pretium. Hendrerit dolor magna eget est lorem ipsum dolor. Sit amet consectetur adipiscing elit duis. Quis varius quam quisque id diam vel. Adipiscing vitae proin sagittis nisl. Porttitor rhoncus dolor purus non enim praesent elementum. Sed vulputate odio ut enim.\n"
																				"\n"
																				"Eget magna fermentum iaculis eu. Pellentesque massa placerat duis ultricies lacus sed turpis tincidunt. Purus in massa tempor nec. Semper eget duis at tellus at urna condimentum mattis. Lobortis feugiat vivamus at augue. Felis eget velit aliquet sagittis id consectetur purus ut faucibus. Id diam maecenas ultricies mi eget. Vulputate sapien nec sagittis aliquam. Odio morbi quis commodo odio aenean sed. Sit amet nulla facilisi morbi. Fringilla urna porttitor rhoncus dolor purus non enim. Sed odio morbi quis commodo odio aenean.\n"
																				"\n"
																				"Suscipit tellus mauris a diam. Congue nisi vitae suscipit tellus mauris. Et netus et malesuada fames ac turpis egestas sed tempus. Viverra accumsan in nisl nisi. Sodales neque sodales ut etiam sit amet nisl purus in. Eget mauris pharetra et ultrices neque ornare aenean euismod. In nulla posuere sollicitudin aliquam ultrices sagittis orci. Consequat ac felis donec et odio pellentesque diam volutpat. Euismod elementum nisi quis eleifend quam adipiscing vitae. Placerat orci nulla pellentesque dignissim enim sit amet venenatis urna. Aliquam nulla facilisi cras fermentum odio eu feugiat pretium nibh. Fringilla phasellus faucibus scelerisque eleifend donec pretium vulputate. Facilisis gravida neque convallis a cras semper auctor neque vitae. Quis enim lobortis scelerisque fermentum dui faucibus in. Arcu non odio euismod lacinia at. Libero enim sed faucibus turpis in eu. Magna ac placerat vestibulum lectus. Nisl purus in mollis nunc sed. Condimentum vitae sapien pellentesque habitant morbi tristique senectus et. Eu mi bibendum neque egestas congue quisque.\n"
																				"\n"
																				"A lacus vestibulum sed arcu. Massa tempor nec feugiat nisl pretium fusce id velit. Enim nec dui nunc mattis enim ut. Faucibus ornare suspendisse sed nisi lacus sed. Hendrerit dolor magna eget est lorem ipsum dolor sit amet. Congue eu consequat ac felis donec et. In dictum non consectetur a erat. Rhoncus aenean vel elit scelerisque mauris pellentesque. Purus sit amet volutpat consequat. Non pulvinar neque laoreet suspendisse interdum consectetur libero id. Pretium vulputate sapien nec sagittis. Egestas egestas fringilla phasellus faucibus scelerisque eleifend donec pretium. Vulputate eu scelerisque felis imperdiet proin fermentum leo. Est lorem ipsum dolor sit.\n"
																				"\n"
																				"Id venenatis a condimentum vitae. Accumsan sit amet nulla facilisi morbi tempus iaculis urna id. Faucibus ornare suspendisse sed nisi lacus sed viverra tellus in. Purus faucibus ornare suspendisse sed nisi. At tempor commodo ullamcorper a lacus vestibulum. Scelerisque in dictum non consectetur a erat nam at. Massa massa ultricies mi quis hendrerit. Aliquam vestibulum morbi blandit cursus risus. Neque egestas congue quisque egestas. Faucibus purus in massa tempor nec feugiat nisl pretium fusce. Ut consequat semper viverra nam libero justo laoreet sit amet. Semper feugiat nibh sed pulvinar proin gravida. Orci ac auctor augue mauris augue neque gravida.\n"
																				"\n"
																				"Commodo odio aenean sed adipiscing diam donec adipiscing tristique risus. Diam ut venenatis tellus in. Enim neque volutpat ac tincidunt vitae semper quis lectus. At quis risus sed vulputate. Iaculis eu non diam phasellus vestibulum lorem sed risus ultricies. Etiam erat velit scelerisque in. Sed augue lacus viverra vitae congue eu. Massa tempor nec feugiat nisl pretium fusce. Nulla posuere sollicitudin aliquam ultrices. Gravida neque convallis a cras semper auctor neque. Id diam vel quam elementum pulvinar etiam non. Eget dolor morbi non arcu risus quis. Massa placerat duis ultricies lacus sed. Habitasse platea dictumst vestibulum rhoncus est pellentesque elit. Nascetur ridiculus mus mauris vitae ultricies leo integer. Ornare arcu odio ut sem nulla pharetra diam.\n"
																				"\n"
																				"Nisi lacus sed viverra tellus in. Vitae ultricies leo integer malesuada nunc vel. Ultricies integer quis auctor elit sed. Odio aenean sed adipiscing diam. Commodo elit at imperdiet dui accumsan sit amet. Sollicitudin aliquam ultrices sagittis orci a. Hac habitasse platea dictumst vestibulum rhoncus est pellentesque. Gravida quis blandit turpis cursus in hac habitasse. Purus sit amet volutpat consequat mauris nunc congue nisi. Sed felis eget velit aliquet sagittis. Vestibulum rhoncus est pellentesque elit ullamcorper dignissim. Metus dictum at tempor commodo ullamcorper a lacus vestibulum. Ac felis donec et odio. Volutpat ac tincidunt vitae semper quis lectus nulla. Eleifend mi in nulla posuere sollicitudin. Neque laoreet suspendisse interdum consectetur libero id faucibus. Neque ornare aenean euismod elementum. Arcu bibendum at varius vel pharetra.\n"
																				"\n"
																				"Sapien eget mi proin sed libero enim sed. Egestas egestas fringilla phasellus faucibus scelerisque eleifend donec pretium. Vitae congue mauris rhoncus aenean vel elit scelerisque. Nunc mattis enim ut tellus elementum sagittis. Vulputate odio ut enim blandit volutpat maecenas. In cursus turpis massa tincidunt dui ut ornare. Sit amet consectetur adipiscing elit duis tristique. Dictum sit amet justo donec enim diam. Volutpat est velit egestas dui id ornare arcu odio. At urna condimentum mattis pellentesque id nibh. Pharetra diam sit amet nisl suscipit adipiscing bibendum est ultricies. Pellentesque habitant morbi tristique senectus et netus et malesuada fames. Sed turpis tincidunt id aliquet risus. Ipsum nunc aliquet bibendum enim. Ut porttitor leo a diam. Vitae suscipit tellus mauris a diam maecenas sed enim ut. Mauris vitae ultricies leo integer malesuada. Egestas sed tempus urna et pharetra pharetra massa massa. Tellus in hac habitasse platea dictumst vestibulum rhoncus est. Imperdiet nulla malesuada pellentesque elit eget gravida cum sociis.\n"
																				"\n"
																				"Vulputate dignissim suspendisse in est ante in nibh. Vulputate dignissim suspendisse in est ante in nibh mauris. Cursus euismod quis viverra nibh cras pulvinar mattis nunc. Ac tortor vitae purus faucibus ornare. Massa ultricies mi quis hendrerit dolor magna eget. Mollis nunc sed id semper risus in. Elit at imperdiet dui accumsan sit amet. Mus mauris vitae ultricies leo. Id leo in vitae turpis massa sed elementum. Diam vulputate ut pharetra sit amet aliquam id diam maecenas. Est velit egestas dui id ornare arcu odio ut. Ultricies integer quis auctor elit sed vulputate mi sit. Bibendum ut tristique et egestas. Mattis enim ut tellus elementum sagittis vitae et leo duis. Id faucibus nisl tincidunt eget nullam non. At consectetur lorem donec massa sapien faucibus et molestie ac. Est pellentesque elit ullamcorper dignissim cras tincidunt lobortis feugiat. Vestibulum lorem sed risus ultricies tristique. Fames ac turpis egestas maecenas pharetra convallis posuere morbi.\n"
																				"\n"
																				"Facilisis volutpat est velit egestas. Hendrerit dolor magna eget est. Varius sit amet mattis vulputate enim nulla aliquet porttitor lacus. Id cursus metus aliquam eleifend mi in nulla posuere. At elementum eu facilisis sed odio morbi quis commodo. Diam ut venenatis tellus in. Morbi blandit cursus risus at ultrices mi tempus imperdiet nulla. Sed euismod nisi porta lorem. Pellentesque dignissim enim sit amet. Accumsan sit amet nulla facilisi.\n"
																				"\n"
																				"Fringilla est ullamcorper eget nulla facilisi etiam. Nunc sed id semper risus in hendrerit gravida rutrum. Egestas fringilla phasellus faucibus scelerisque eleifend donec pretium vulputate sapien. Maecenas pharetra convallis posuere morbi leo urna molestie at. Odio facilisis mauris sit amet massa. Lacus vestibulum sed arcu non odio euismod lacinia. Cras fermentum odio eu feugiat pretium nibh ipsum consequat. At lectus urna duis convallis. Egestas pretium aenean pharetra magna ac. Leo a diam sollicitudin tempor id eu. Mauris in aliquam sem fringilla ut morbi tincidunt augue interdum.\n"
																				"\n"
																				"Elit scelerisque mauris pellentesque pulvinar pellentesque habitant morbi tristique senectus. Sed elementum tempus egestas sed sed risus pretium quam. Metus dictum at tempor commodo ullamcorper. Egestas sed sed risus pretium quam vulputate dignissim. Bibendum at varius vel pharetra vel turpis. Condimentum id venenatis a condimentum. Non nisi est sit amet facilisis. Ac auctor augue mauris augue neque gravida in. Facilisis volutpat est velit egestas dui id ornare arcu. Posuere ac ut consequat semper. Sagittis nisl rhoncus mattis rhoncus. Hac habitasse platea dictumst vestibulum rhoncus est. Dictumst vestibulum rhoncus est pellentesque elit ullamcorper dignissim. Venenatis lectus magna fringilla urna porttitor rhoncus. Elit duis tristique sollicitudin nibh sit. Turpis in eu mi bibendum neque egestas congue quisque. Et malesuada fames ac turpis egestas sed.\n"
																				"\n"
																				"Urna id volutpat lacus laoreet non curabitur gravida arcu. Nisi quis eleifend quam adipiscing vitae proin. Risus sed vulputate odio ut enim blandit volutpat maecenas. Elementum nisi quis eleifend quam adipiscing vitae proin. Iaculis nunc sed augue lacus viverra vitae congue. Facilisis mauris sit amet massa vitae tortor. Platea dictumst quisque sagittis purus sit amet. Quam viverra orci sagittis eu volutpat. At quis risus sed vulputate odio ut enim blandit volutpat. Quis risus sed vulputate odio.\n"
																				"\n"
																				"Neque gravida in fermentum et. Elit duis tristique sollicitudin nibh sit amet commodo. Mauris sit amet massa vitae tortor condimentum lacinia quis. Fermentum et sollicitudin ac orci phasellus egestas tellus rutrum tellus. Ac auctor augue mauris augue neque gravida in. Quisque egestas diam in arcu. Nibh ipsum consequat nisl vel pretium. Risus at ultrices mi tempus. Tellus id interdum velit laoreet id donec ultrices tincidunt arcu. Accumsan sit amet nulla facilisi morbi tempus iaculis urna id. Vestibulum rhoncus est pellentesque elit ullamcorper dignissim cras. Tempor nec feugiat nisl pretium fusce id velit ut tortor. Mi proin sed libero enim sed faucibus turpis. Augue ut lectus arcu bibendum at varius. Quam lacus suspendisse faucibus interdum posuere lorem ipsum dolor. Pharetra convallis posuere morbi leo urna. Massa vitae tortor condimentum lacinia quis vel. Nibh sit amet commodo nulla facilisi nullam. Et sollicitudin ac orci phasellus egestas tellus rutrum tellus pellentesque."));
}

void	Phonebook::_addContact( Contact const & new_contact ) {

	if (Contact::get_nbContacts() % MAX_CONTACTS == 0)
		this->_contacts[MAX_CONTACTS - 1] = new_contact;
	else
		this->_contacts[(Contact::get_nbContacts() % MAX_CONTACTS) - 1] = new_contact;
}

void	Phonebook::_printContact( Contact const & to_print ) const {

	std::cout << std::endl
			  << std::setw(14) << "First name: " << to_print.getFirstN( ) << std::endl
			  << std::setw(14) << "Last name: " << to_print.getLastN( ) << std::endl
			  << std::setw(14) << "Nickname: " << to_print.getNickN( ) << std::endl
			  << std::setw(14) << "Phone number: " << to_print.getPhoneN( ) << std::endl
			  << std::setw(14) << "Dark Secret: " << to_print.getDarkS( )
			  << std::endl << std::endl;
}

void	Phonebook::_printSearch( ) const {

	std::cout << std::endl;
	std::cout << std::setw(COL_WIDTH) << "index" << " | "
			  << std::setw(COL_WIDTH) << "first name" << " | "
			  << std::setw(COL_WIDTH) << "last name" << " | "
			  << std::setw(COL_WIDTH) << "nickname" << std::endl;
	for (int i = 0; i < Contact::get_nbContacts() && i < MAX_CONTACTS; i++)
	{
		std::cout << std::setw(COL_WIDTH) << i + 1 << " | "
				  << std::setw(COL_WIDTH) << _shrink(this->_contacts[i].getFirstN()) << " | "
				  << std::setw(COL_WIDTH) << _shrink(this->_contacts[i].getLastN()) << " | "
				  << std::setw(COL_WIDTH) << _shrink(this->_contacts[i].getNickN())
				  << std::endl;
	}
	std::cout << std::endl;
}

Contact		Phonebook::_getContact( int i ) const {

	return this->_contacts[i];
}

std::string	Phonebook::_shrink( std::string src ) const {

	if (src.size() > 10)
	{
		src.resize(10);
		src[9] = '.';
	}
	return src;
}
