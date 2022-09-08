#include "Lsed.hpp"

void	Lsed::initLoser( char **argv ) {

	this->file = std::string(argv[1]);
	this->find = std::string(argv[2]);
	this->replace = std::string(argv[3]);
	this->in_file.exceptions ( std::fstream::badbit );
	this->out_file.exceptions ( std::fstream::failbit | std::fstream::badbit );
}

void	Lsed::tryOpen( void ) {

	try
    {
        if (this->in_file.is_open())
        {
            std::cerr << this->in_file << " is already open, quitting.." << std::endl;
            exit(1);
        }
		this->in_file.open( this->file, std::fstream::in );
	}
	catch(std::fstream::failure & e)
    {
		std::cerr << "Exception opening " << this->in_file << std::endl;
		exit(2);
	}
	if (!this->in_file)
	{
		std::cout << this->in_file << " does not exist or no permission to read from it, quitting.." << std::endl;
		exit(3);
	}
	try
    {
        if (this->out_file.is_open())
        {
            std::cerr << this->out_file << " is already open, quitting.." << std::endl;
            exit(4);
        }
        this->out_file.open(this->file.append(".replace"), std::fstream::out | std::fstream::trunc);
    }
	catch(std::fstream::failure & e)
    {
		std::cerr << "Exception opening" << this->out_file << ", write protected?" << std::endl;
		exit(5);
	}
}

void	Lsed::tryReadWrite( void ) {

	std::string	line;

	try
    {
		while (std::getline(this->in_file, line))
        {
			this->tryWrite(line);
        }
	}
	catch(std::fstream::failure & e)
    {
		std::cerr << "Exception reading from " << this->in_file << std::endl;
        exit(6);
	}
	std::cout << "Written changes to '" << this->file << "'" << std::endl;
}

void	Lsed::tryWrite( std::string line ) {

    size_t  pos = 0;

	try
    {
        while (pos != std::string::npos)
        {
            pos = line.find(this->find, pos);
            if (pos == std::string::npos)
            {
                this->out_file << line << std::endl;
            }
            else
            {
                line = line.substr(0, pos) + this->replace + line.substr(pos + this->find.size(), std::string::npos);
                pos += this->find.size();
            }
        }
	}
	catch(std::fstream::failure & e)
    {
		std::cerr << "Exception writing " << this->out_file << std::endl;
        exit(7);
	}
}

void	Lsed::tryClose( void ) {

	try
    {
        this->in_file.close();
    }
	catch(std::fstream::failure & e)
    {
		std::cerr << "Exception closing " << this->in_file << std::endl;
		exit(8);
	}
	try
    {
        this->out_file.close();
    }
	catch(std::fstream::failure & e)
    {
		std::cerr << "Exception closing " << this->out_file << std::endl;
		exit(9);
	}
}
