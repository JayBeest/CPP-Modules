#ifndef ITER_H
# define ITER_H

template<typename T>
void	iter(T arrayAddress[], int arrayLength, void(*function)(T &)) {

	for (int i = 0; i < arrayLength; i++)
	{
		function(arrayAddress[i]);
	}
}

template<typename T>
void	printElement( T & element ) {

	std::cout << "element: " << element << std::endl;
}

template<typename T>
void	plusPlus( T & element ) {

	++element;
}

template<>
void	plusPlus( std::string & element) {

	element += " >just added this<";
}


#endif
