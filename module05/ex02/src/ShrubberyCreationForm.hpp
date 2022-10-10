#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include <iostream>
# include "Form.hpp"

class ShrubberyCreationForm : public Form {

public:

	int							getId( ) const;

	explicit					ShrubberyCreationForm( const std::string & target );
								ShrubberyCreationForm( );
								ShrubberyCreationForm( const ShrubberyCreationForm & other );
								~ShrubberyCreationForm( );
	ShrubberyCreationForm &		operator=( const ShrubberyCreationForm & rhs );

	void						doStuff() const;

private:


};

#endif
