#include "Lsed.hpp"

///			Public:

bool	Lsed::setupLoser( char **argv ) {

	this->file = std::string(argv[1]);
	this->s1 = std::string(argv[2]);
//	this->s1 = '\n';
	this->s2 = std::string(argv[3]);
	this->in_file.exceptions ( std::fstream::badbit );
	this->out_file.exceptions ( std::fstream::failbit | std::fstream::badbit );

	return true;
}

bool	Lsed::tryOpen( void ) {

	std::cout << "this file: " << this->file << std::endl;

	try {
		this->in_file.open( this->file, std::fstream::in );
	}
	catch(std::fstream::failure & e) {
		std::cerr << "Exception opening in_file" << std::endl;
		return false;
	}
	try { this->out_file.open(this->file + ".replace", std::fstream::out | std::fstream::trunc); }
	catch(std::fstream::failure & e) {
		std::cerr << "Exception opening out_file" << std::endl;
		return false;
	}

	return true;
}

bool	Lsed::readWrite( void ) {

	char	c;

//	try {
	while (this->in_file.get(c))    /////////////getline miss wel veel beter!!! met exception voor '\n'
		this->checkC(c);
//	}
//	catch(std::fstream::failure & e) {
//		std::cerr << "Exception "
//	}

	return true;
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

///			Constructor/Destroyer

Lsed::Lsed(	) : s1_ptr(nullptr), s2_ptr(nullptr) {

										// TODO not counting default constructor

}

Lsed::Lsed( Lsed const & other) : s1(nullptr), s2(nullptr) {

	if (this != &other)
	{
		if (other.s1_ptr)
			this->s1_ptr = new std::string();
		else
			this->s1_ptr = nullptr;
		if (other.s2_ptr)
			this->s2_ptr = new std::string();
		else
			this->s2_ptr = nullptr;
		// TODO
	}
}

Lsed::~Lsed( ) {

	delete s1_ptr;
	// TODO

}

Lsed &	Lsed::operator=( Lsed const & rhs ) {

	delete this->s1_ptr;
	delete this->s2_ptr;
	if (this != &rhs)
	{
		if (rhs.s1_ptr)
			this->s1_ptr = new std::string();
		else
			this->s1_ptr = nullptr;
		if (rhs.s2_ptr)
			this->s2_ptr = new std::string();
		else
			this->s2_ptr = nullptr;
		// TODO
	}
	return *this;
}

///			Functions/Methods

void	Lsed::checkC(char c ) {

	static size_t	size = 0;

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

///			Private:

