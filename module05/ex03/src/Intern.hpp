#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include "Form.hpp"

class Intern {

public:

					Intern( );
					Intern( const Intern & other );
					~Intern( );
	Intern &		operator=( const Intern & rhs );

	AForm *			makeForm( const std::string & name, const std::string & target) const;

	static void		makeSilent( void );

private:

	static bool		_loud;

};

#endif
