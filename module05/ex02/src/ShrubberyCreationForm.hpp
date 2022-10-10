#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include <iostream>
# include "Form.hpp"

class ShrubberyCreationForm : public AForm {

public:

	explicit					ShrubberyCreationForm( const std::string & target );
								ShrubberyCreationForm( const ShrubberyCreationForm & other );
								~ShrubberyCreationForm( );
	ShrubberyCreationForm &		operator=( const ShrubberyCreationForm & rhs );

	virtual void				executeConcrete( const Bureaucrat & executor ) const;

private:

								ShrubberyCreationForm( );

};

#endif
