#include "Lsed.hpp"

int main (int argc, char **argv) {

	Lsed	loser_sed;

	if (argc != 4)
	{
		std::cout << "error - loser_sed needs three arguments" << std::endl;
		return 1;
	}
	loser_sed.initLoser(argv);
	loser_sed.tryOpen();
    loser_sed.tryReadWrite();
	loser_sed.tryClose();
	return 0;
}
