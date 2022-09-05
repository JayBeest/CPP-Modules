#include "Lsed.hpp"

int main (int argc, char **argv) {

	Lsed	looser_sed;

	if (argc != 4) {
		std::cout << "error - loser_sed needs three arguments" << std::endl;
		return 1;
	}
	looser_sed.initLoser(argv);
	looser_sed.tryOpen();
    looser_sed.tryReadWrite();
	looser_sed.tryClose();
	return 0;
}
