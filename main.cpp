#include <iostream>
#include <stdio.h>
#include "Sample.class.hpp"

int gl_var = 1;
int f(void){return 2;}

namespace Foo {
	int gl_var = 3;
	int f(void){return 4;}
}

namespace Bar {
	int gl_var = 5;
	int f(void){return 6;}
}

namespace Muf = Bar;

int main( void) {

	Sample1   test( 3.14 );

	return 0;
}
