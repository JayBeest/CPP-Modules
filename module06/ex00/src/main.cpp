#include "ScalarConverter.hpp"

int main (int argc, char **argv) {

	ScalarConverter::makeSilent();

//	ScalarConverter test("5");
//	ScalarConverter test2("fsdaf");
//	ScalarConverter test3("g");
//	ScalarConverter test4("0");
//	ScalarConverter test5("0.0");
//	ScalarConverter test6("0.0f");
//	ScalarConverter test6a("0.0fn");
//	ScalarConverter test7("-0.0f");
//	ScalarConverter test8("-2");
//	ScalarConverter test9("-0.2");
//	ScalarConverter test10("");
//	ScalarConverter test11("4.");
//	ScalarConverter test12(".3");
//	ScalarConverter test13("0.0ff");
//	ScalarConverter test14("10..0f");
//	ScalarConverter test15("d");
//	ScalarConverter test16("$");
//	ScalarConverter test17("f");
//	ScalarConverter test18("c");
//	ScalarConverter test19(" ");
//	ScalarConverter test20("12.32332");
//	ScalarConverter test21("12.32332f");

	if (argc == 2)
	{
		ScalarConverter test(argv[1]);
	}
	return 0;
}
