#include "ScalarConverter.hpp"
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>

///			Public:

///			Getters / Setters

///			Constructor / Destructor

ScalarConverter::ScalarConverter( const std::string & input )
: _type(DEFAULT), _input(input), _int(0), _char(0), _float(0), _double(0) {

}

ScalarConverter::~ScalarConverter( ) {

}

///			Functions / Methods

void ScalarConverter::detectType( ) {

	if (_input.empty()) {
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
		_type = INT;
		int64_t temp = std::stoll(_input);
		if (temp > std::numeric_limits<int>::max())
		{
			std::cout << "int overflowing, using INT_MAX" << std::endl;
			_int = std::numeric_limits<int>::max();
		}
		else if (temp < std::numeric_limits<int>::min())
		{
			std::cout << "int underflowing, using INT_MIN.." << std::endl;
			_int = std::numeric_limits<int>::min();
		}
		else
		{
			_int = std::stoi(_input);
//			std::cout << "int found: '" << _input << "'" << std::endl;
		}
		return ;
	}
	if (_input[found] == '.' && found > 0)
	{
		++found;
		if (_input.find_first_not_of("0123456789", found) == std::string::npos && _input[found] != '\0')
		{
			_type = DOUBLE;
			_double = std::stod(_input);
//			std::cout << "double found: '" << _input << "'" << std::endl;
			return ;
		}
		if (_input[_input.find_first_of('f') + 1] == '\0')
		{
			if (_input.find_first_not_of("0123456789f", found) == std::string::npos)
			{
				_type = FLOAT;
				_float = std::stof(_input);
//				std::cout << "float found: '" << _input << "'" << std::endl;
				return ;
			}
		}
	}
	_type = DEFAULT;
	std::cerr << "->input unsupported: '" << _input << "'" << std::endl;
}

void	ScalarConverter::castType( ) {

	switch (_type)
	{
		case INT:
			std::cout << "casting int: " << _int << std::endl;
			castInt();
			break ;
		case CHAR:
			std::cout << "casting char: " << _char << std::endl;
			castChar();
			break ;
		case DOUBLE:
			std::cout << "casting double: " << _double << std::endl;
			castDouble();
			break ;
		case FLOAT:
			std::cout << "casting float: " << _float << "f" << std::endl;
			castFloat();
			break ;
		default:
			std::cout << "error: <default_type>" << std::endl;
	}
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
			_char = _input[0];
		}
		else
		{
			std::cerr << "->unsupported, unprintable char found : '" << _input << "'" << std::endl;
			std::exit(1);
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

	if (_int > 255)
	{
		std::cout << "char overflow.." << std::endl;
	}
	else if (_int < 0)
	{
		std::cout << "char underflow.." << std::endl;
	}
	_char = static_cast<unsigned char>(_int);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
}

void	ScalarConverter::castChar( ) {

	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
}

void	ScalarConverter::castDouble( ) {

	if (_double > std::numeric_limits<int>::max())
	{
		std::cout << "int overflow, cast not really possible.." << std::endl;
	}
	else if (_double < std::numeric_limits<int>::min())
	{
		std::cout << "int underflow, casting not really possible.." << std::endl;
	}
	_int = static_cast<int>(_double);
	if (_double > 255)
	{
		std::cout << "char overflow.." << std::endl;
	}
	else if (_double < 0)
	{
		std::cout << "char underflow.." << std::endl;
	}
	_char = static_cast<unsigned char>(_double);
	if (_double > std::numeric_limits<float>::max())
	{
		std::cout << "float overflow, cast not really possible.." << std::endl;
	}
	else if (_double < std::numeric_limits<float>::lowest())
	{
		std::cout << "float underflow, cast not really possible.." << std::endl;
	}
	_float = static_cast<float>(_double);
}

void	ScalarConverter::castFloat( ) {

	if (_float > static_cast<float>(std::numeric_limits<int>::max()))
	{
		std::cout << "int overflow, cast not really possible.." << std::endl;
	}
	else if (_float < static_cast<float>(std::numeric_limits<int>::min()))
	{
		std::cout << "int underflow, casting not really possible.." << std::endl;
	}
	_int = static_cast<int>(_float);
	if (_float > 255)
	{
		std::cout << "char overflow.." << std::endl;
	}
	else if (_float < 0)
	{
		std::cout << "char underflow.." << std::endl;
	}
	_char = static_cast<unsigned char>(_float);
	_double = static_cast<double>(_float);
}

void	ScalarConverter::printInt( ) const {

	if (_float != _float)
	{
		std::cout  << "int: impossible (not a number)" << std::endl;
	}
	else
	{
		std::cout << "int: " << _int << std::endl;
	}
}

void	ScalarConverter::printChar( ) const {

	if (_float != _float)
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

	std::cout << std::fixed;
	if (_double - static_cast<int>(_double) == 0)
	{
		std::cout << std::setprecision(1);
	}
	std::cout << "double: " << _double << std::endl;
	std::cout << std::defaultfloat;
}

void	ScalarConverter::printFloat( ) const {

	std::cout << std::fixed;
	if (_float - static_cast<int>(_float) == 0)
	{
		std::cout << std::setprecision(1);
	}
	std::cout << "float: " << _float << "f" << std::endl;
	std::cout << std::defaultfloat;
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
