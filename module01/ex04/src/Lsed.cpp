#include "Lsed.hpp"

void	Lsed::initLoser( char **argv ) {

	this->file = std::string(argv[1]);
	this->s1 = std::string(argv[2]);
	this->s2 = std::string(argv[3]);
	this->in_file.exceptions ( std::fstream::badbit );
	this->out_file.exceptions ( std::fstream::failbit | std::fstream::badbit );
}

void	Lsed::tryOpen( void ) {

	try
    {
		this->in_file.open( this->file, std::fstream::in );
	}
	catch(std::fstream::failure & e)
    {
		std::cerr << "Exception opening in_file" << std::endl;
		exit(1);
	}
	if (!this->in_file)
	{
		std::cout << "in_file does not exist or no permission to read from it, quitting.." << std::endl;
		exit(2);
	}
	try
    {
        this->out_file.open(this->file + ".replace", std::fstream::out | std::fstream::trunc);
    }
	catch(std::fstream::failure & e)
    {
		std::cerr << "Exception opening out_file" << std::endl;
		exit(3);
	}
}

void	Lsed::tryReadWrite( void ) {

	char	c;

	try
    {
		while (this->in_file.get(c))
        {
			this->tryWrite(c);
        }
	}
	catch(std::fstream::failure & e)
    {
		std::cerr << "Exception reading in_file";
        exit(4);
	}
	std::cout << "Written changes to: '" << this->file + ".replace" << "'" << std::endl;
}

void	Lsed::tryWrite( char c ) {

	static size_t	nbr_sequential_chars = 0;

	try
    {
		if (c == this->s1.c_str()[nbr_sequential_chars])
		{
			nbr_sequential_chars++;
			if (nbr_sequential_chars == this->s1.length())
			{
				this->out_file << s2;
                nbr_sequential_chars = 0;
			}
		}
		else if (nbr_sequential_chars > 0)
		{
			this->out_file << this->s1.substr(0, nbr_sequential_chars) << c;
            nbr_sequential_chars = 0;
		}
		else
			this->out_file << c;
	}
	catch(std::fstream::failure & e)
    {
		std::cerr << "Exception writing out_file" << std::endl;
        exit(5);
	}

}

void	Lsed::tryClose( void ) {

	try
    {
        this->in_file.close();
    }
	catch(std::fstream::failure & e)
    {
		std::cerr << "Exception closing in_file" << std::endl;
		exit(6);
	}
	try
    {
        this->out_file.close();
    }
	catch(std::fstream::failure & e)
    {
		std::cerr << "Exception closing out_file" << std::endl;
		exit(7);
	}
}
