#include "ScalarConverter.hpp"
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>

///			Public:

///			Getters / Setters

e_type	ScalarConverter::getType( ) const {

	return _type;
}

///			Constructor / Destructor

ScalarConverter::ScalarConverter( const std::string & input )
: _type(DEFAULT), _input(input), _int(0), _char(0), _float(0), _double(0) {

	_functionPtr[INT] = &ScalarConverter::castInt;
	_functionPtr[CHAR] = &ScalarConverter::castChar;
	_functionPtr[DOUBLE] = &ScalarConverter::castDouble;
	_functionPtr[FLOAT] = &ScalarConverter::castFloat;
}

ScalarConverter::~ScalarConverter( ) {

}

///			Functions / Methods

void ScalarConverter::detectAndSetScalarType( ) {

	if (_input.empty())
	{
		std::cout << "empty input.." << std::endl;
		_type = DEFAULT;
		return ;
	}
	if (isSuperSmall())
	{
		return ;
	}
	if (isSpecial())
	{
		return ;
	}
	std::string::size_type	found = 0;
	while(isspace(_input[found]))
	{
		found++;
	}
	if (_input[0] == '-' || _input[0] == '+')
	{
		found++;
	}
	found = _input.find_first_not_of("0123456789", found);
	if (found == std::string::npos)
	{
		try {
			_int = std::stoi(_input);
			_type = INT;
		}
		catch (std::out_of_range & e) {
			std::cout << "error reading int: out of range" << std::endl;
		}
		return ;
	}
	if (_input[found] == '.' && found > 0)
	{
		++found;
		if (_input.find_first_not_of("0123456789", found) == std::string::npos && _input[found] != '\0')
		{
			try {
				_double = std::stod(_input);
				_type = DOUBLE;
			}
			catch (std::out_of_range & e) {
				std::cerr << "error reading double: out of range" << std::endl;
			}
			return ;
		}
		if (_input[_input.find_first_of('f') + 1] == '\0' && \
			_input.find_first_not_of("0123456789f", found) == std::string::npos)
		{
			try {
				_float = std::stof(_input);
				_type = FLOAT;
			}
			catch (std::out_of_range & e) {
				std::cerr << "error reading float: out of range" << std::endl;
			}
			return ;
		}
	}
	std::cerr << "->input unsupported: '" << _input << "'" << std::endl;
}

void	ScalarConverter::castToOtherTypes( ) {

	if (_type == DEFAULT)
	{
		std::cout << "error: <default_type>" << std::endl;
		std::exit(1);
	}
	(this->*_functionPtr[_type])();
}

void	ScalarConverter::printAll( ) {

	printInt();
	printChar();
	printFloat();
	printDouble();
}

///			Private:

bool	ScalarConverter::isSuperSmall( ) {

	if (_input.size() == 1)
	{
		if (std::isdigit(_input[0]))
		{
			_type = INT;
			_int = std::stoi(_input);
		}
		else if (std::isprint(_input[0]))
		{
			_type = CHAR;
			_char = static_cast<unsigned char>(_input[0]);
		}
		else
		{
			std::cerr << "->input unsupported: unprintable char found" << std::endl;
		}
		return true;
	}
	return false;
}

bool	ScalarConverter::isSpecial( ) {

	if (_input == "nan")
	{
		_type = DOUBLE;
		_double = NAN;
	}
	else if (_input == "nanf")
	{
		_type = FLOAT;
		_float = NAN;
	}
	else if (_input == "-inf")
	{
		_type = DOUBLE;
		_double = -1.0 * INFINITY;
	}
	else if (_input == "-inff")
	{
		_type = FLOAT;
		_float = -1.0f * INFINITY;
	}
	else if (_input == "+inf" || _input == "inf")
	{
		_type = DOUBLE;
		_double = INFINITY;
	}
	else if (_input == "+inff" || _input == "inff")
	{
		_type = FLOAT;
		_float = INFINITY;
	}
	else
	{
		return false;
	}
	return true;
}

void	ScalarConverter::castInt( ) {

	printInt();
	if (_int > 255)
	{
		std::cout << "char overflow.." << std::endl;
	}
	else if (_int < 0)
	{
		std::cout << "char underflow.." << std::endl;
	}
	_char = static_cast<unsigned char>(_int);
	printChar();
	_float = static_cast<float>(_int);
	printFloat();
	_double = static_cast<double>(_int);
	printDouble();
}

void	ScalarConverter::castChar( ) {

	_int = static_cast<int>(_char);
	printInt();
	printChar();
	_float = static_cast<float>(_char);
	printFloat();
	_double = static_cast<double>(_char);
	printDouble();
}

void	ScalarConverter::castDouble( ) {

	if (_double > std::numeric_limits<int>::max())
	{
		std::cout << "int overflow, type conversion impossible, casting anyway.." << std::endl;
	}
	else if (_double < std::numeric_limits<int>::min())
	{
		std::cout << "int underflow, type conversion impossible, casting anyway.." << std::endl;
	}
	_int = static_cast<int>(_double);
	printInt();
	if (_double > 255)
	{
		std::cout << "char overflow, type conversion impossible, casting anyway.." << std::endl;
	}
	else if (_double < 0)
	{
		std::cout << "char underflow, type conversion impossible, casting anyway.." << std::endl;
	}
	_char = static_cast<unsigned char>(_double);
	printChar();
	if (_double > std::numeric_limits<float>::max())
	{
		std::cout << "float overflow, type conversion impossible, casting anyway.." << std::endl;
	}
	else if (_double < std::numeric_limits<float>::lowest())
	{
		std::cout << "float underflow, type conversion impossible, casting anyway.." << std::endl;
	}
	_float = static_cast<float>(_double);
	printFloat();
	printDouble();
}

void	ScalarConverter::castFloat( ) {

	if (_float > static_cast<float>(std::numeric_limits<int>::max()))
	{
		std::cout << "int overflow, type conversion impossible, casting anyway.." << std::endl;
	}
	else if (_float < static_cast<float>(std::numeric_limits<int>::min()))
	{
		std::cout << "int underflow, type conversion impossible, casting anyway.." << std::endl;
	}
	_int = static_cast<int>(_float);
	printInt();
	if (_float > 255)
	{
		std::cout << "char overflow, type conversion impossible, casting anyway.." << std::endl;
	}
	else if (_float < 0)
	{
		std::cout << "char underflow, type conversion impossible, casting anyway.." << std::endl;
	}
	_char = static_cast<unsigned char>(_float);
	printChar();
	printFloat();
	_double = static_cast<double>(_float);
	printDouble();
}

void	ScalarConverter::printInt( ) const {

	if (_float != _float || _double != _double)
	{
		std::cout  << "int: impossible" << std::endl;
	}
	else
	{
		std::cout << "int: " << _int << std::endl;
	}
}

void	ScalarConverter::printChar( ) const {

	if (_float != _float || _double != _double)
	{
		std::cout  << "char: impossible" << std::endl;
	}
	else if (isprint(_char))
	{
		std::cout  << "char: '" << _char << "'" << std::endl;
	}
	else
	{
		std::cout << "char: Non displayable" << std::endl;
	}
}

void	ScalarConverter::printDouble( ) const {

	if (_double - static_cast<int>(_double) == 0.0)
	{
		std::cout << std::fixed;
		std::cout << std::setprecision(1);
	}
	std::cout << "double: " << _double << std::endl;
}

void	ScalarConverter::printFloat( ) const {

	if (_float - static_cast<int>(_float) == 0.0f)
	{
		std::cout << std::fixed;
		std::cout << std::setprecision(1);
	}
	std::cout << "float: " << _float << "f" << std::endl;
}


ScalarConverter::ScalarConverter( ) {

}

ScalarConverter::ScalarConverter( const ScalarConverter & other ) {

	if (this != &other)
	{
	  *this = other;
	}
}

ScalarConverter &	ScalarConverter::operator=( const ScalarConverter & rhs ) {

	if (this != &rhs)
	{
	}
	return *this;
}
