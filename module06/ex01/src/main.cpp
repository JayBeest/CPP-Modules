#include <iostream>
#include <iomanip>
#include "Data.hpp"

uintptr_t	serialize(Data * ptr) {

	uintptr_t	raw = reinterpret_cast<uintptr_t>(ptr);
	return raw;
}

Data *	deserialize(uintptr_t raw) {

	Data *	ptr = reinterpret_cast<Data *>(raw);
	return ptr;
}

int main ( ) {

	Data	test;

	std::cout << std::setw(30) << "og test: " << std::setw(3) << test.getData() << " (mem location: " << &test << ")" << std::endl;
	test.setData(42);
	std::cout << std::setw(30) << "after setData: " << std::setw(3) << test.getData() << " (mem location: " << &test << ")" << std::endl;
	uintptr_t testInt = serialize(&test);
	std::cout << std::setw(30) << "after (de)serializing: " << std::setw(3) << deserialize(testInt)->getData() << " (mem location: 0x" << std::hex << testInt << ")" << std::endl;
	deserialize(testInt)->setData(420);
	std::cout << std::setw(30) << "after more deserializing: " << std::setw(3) << std::dec << deserialize(testInt)->getData() << " (mem location: 0x" << std::hex << testInt << ")" << std::endl;
	return 0;
}
