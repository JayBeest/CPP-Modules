#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

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

	int					getInt( ) const;
	char				getChar( ) const;
	float				getFloat( ) const;
	double				getDouble( ) const;

	explicit			ScalarConverter( const std::string & input );
						ScalarConverter( const ScalarConverter & other );
						~ScalarConverter( );
	ScalarConverter &	operator=( const ScalarConverter & rhs );

	static void			makeSilent( void );

private:

	e_type				_type;
	const std::string	_input;
	int					_int;
	char				_char;
	float				_float;
	double				_double;

	static bool			_loud;

	void				castInt( );
	void				castChar( );
	void				castDouble( );
	void				castFloat( );
	void				detectType( );
	void				castType( );
	void				printType( );

						ScalarConverter( );

};

#endif
