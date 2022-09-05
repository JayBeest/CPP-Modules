#include "Lsed.hpp"

void	Lsed::initLoser(char **argv ) {

	this->file = std::string(argv[1]);
	this->s1 = std::string(argv[2]);
	this->s2 = std::string(argv[3]);
	this->in_file.exceptions ( std::fstream::badbit );
	this->out_file.exceptions ( std::fstream::failbit | std::fstream::badbit );
}

bool	Lsed::tryOpen( void ) {

	try {
		this->in_file.open( this->file, std::fstream::in );
	}
	catch(std::fstream::failure & e) {
		std::cerr << "Exception opening in_file" << std::endl;
		return false;
	}
	if (!this->in_file)
	{
		std::cout << "in_file does not exist, quitting.." << std::endl;
		return false;
	}
	try { this->out_file.open(this->file + ".replace", std::fstream::out | std::fstream::trunc); }
	catch(std::fstream::failure & e) {
		std::cerr << "Exception opening out_file" << std::endl;
		return false;
	}

	return true;
}

bool	Lsed::tryReadWrite(void ) {

	char	c;

	try {
		while (this->in_file.get(c))
			this->tryWrite(c);
	}
	catch(std::fstream::failure & e) {
		std::cerr << "Exception reading in_file";
	}
	std::cout << "Written changes to: '" << this->file + ".replace" << "'" << std::endl;

	return true;
}

void	Lsed::tryWrite(char c ) {

	static size_t	size = 0;

	try {
		if (c == this->s1.c_str()[size])
		{
			size++;
			if (size == this->s1.length())
			{
				this->out_file << s2;
				size = 0;
			}
		}
		else if (size > 0)
		{
			this->out_file << this->s1.substr(0, size) << c;
			size = 0;
		}
		else
			this->out_file << c;
	}
	catch(std::fstream::failure & e) {
		std::cerr << "Exception writing out_file" << std::endl;
	}

}

bool	Lsed::tryClose( void ) {

	try { this->in_file.close(); }
	catch(std::fstream::failure & e) {
		std::cerr << "Exception closing in_file" << std::endl;
		return false;
	}
	try { this->out_file.close(); }
	catch(std::fstream::failure & e) {
		std::cerr << "Exception closing out_file" << std::endl;
		return false;
	}

	return true;
}
