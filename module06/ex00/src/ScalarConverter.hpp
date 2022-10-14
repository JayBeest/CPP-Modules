#ifndef SCALAR_CONVERTER_H
# define SCALAR_CONVERTER_H

# include <iostream>

enum e_type {
	INT,
	CHAR,
	FLOAT,
	DOUBLE,
	DEFAULT
};

class ScalarConverter {

public:

	explicit			ScalarConverter( const std::string & input );
						~ScalarConverter( );

	void				detectType( );
	void				castType( );
	void				printAll( );

private:

	e_type				_type;
	const std::string	_input;
	int					_int;
	unsigned char		_char;
	float				_float;
	double				_double;

	bool				isSuperSmall( );
	bool				isSpecial( );
	void				castInt( );
	void				castChar( );
	void				castDouble( );
	void				castFloat( );
	void				printInt( ) const;
	void				printChar( ) const;
	void				printDouble( ) const;
	void				printFloat( ) const;

						ScalarConverter( );
						ScalarConverter( const ScalarConverter & other );
	ScalarConverter &	operator=( const ScalarConverter & rhs );

};

#endif
