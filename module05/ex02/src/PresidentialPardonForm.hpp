#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include <iostream>
# include "Form.hpp"

class PresidentialPardonForm : public AForm {

public:

	explicit					PresidentialPardonForm( const std::string & target );
								PresidentialPardonForm( const PresidentialPardonForm & other );
								~PresidentialPardonForm( );
	PresidentialPardonForm &	operator=( const PresidentialPardonForm & rhs );

	virtual void				executeConcrete( const Bureaucrat & executor ) const;

private:

								PresidentialPardonForm( );

};

#endif
