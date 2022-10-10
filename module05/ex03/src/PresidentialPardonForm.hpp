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


private:

	virtual void				executeConcrete( ) const;
								PresidentialPardonForm( );

};

#endif
