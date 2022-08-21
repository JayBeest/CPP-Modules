#include "Lsed.hpp"

int main (int argc, char **argv) {

	Lsed	looser_sed;

	if (argc != 4) {
		std::cout << "error - loser_sed needs three arguments" << std::endl;
		return 1;
	}
	looser_sed.initLoser(argv);
	if (!looser_sed.tryOpen())
		return 2;
	if (!looser_sed.tryReadWrite())
		return 3;
	if (!looser_sed.tryClose())
		return 4;:

	return 0;
}
