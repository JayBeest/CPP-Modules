#include <iostream>
#include <fstream>
#include <string>
#include "loser_sed.hpp"
#include "Lsed.hpp"

int main (int argc, char **argv)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	Lsed			looser_sed;
	char			c;

	if (argc != 4) {
		std::cout << "error-> loser_sed works with three arguments" << std::endl;
		return 1;
	}
	looser_sed.s1 = std::string(argv[2]);
	looser_sed.s2 = std::string(argv[3]);
	infile.exceptions ( std::ifstream::badbit );
	try {
		infile.open (std::string(argv[1]));
		while (infile.get(c))
			looser_sed.processC(c);
		infile.close();
	}
	catch (std::ifstream::failure & e) {
		std::cerr << "Exception opening/reading/closing file\n";
		return 1;
	}


	return 0;
}




/// Huge stream -> std::string / fstream max size

///