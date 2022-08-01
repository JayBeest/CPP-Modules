#include "Lsed.hpp"

int main (int argc, char **argv)
{
	Lsed			looser_sed;

	if (argc != 4) {
		std::cout << "error-> loser_sed works with three arguments" << std::endl;
		return 1;
	}
	if (!looser_sed.setupLoser(argv))
		return 2;
	if (!looser_sed.tryOpen())
		return 3;
	if (!looser_sed.tryReadWrite())
		return 4;
	if (!looser_sed.tryClose())
		return 5;

	return 0;
}




/// Huge stream -> std::string / fstream max size

///