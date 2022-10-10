#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include <iostream>
# include "Form.hpp"

class RobotomyRequestForm : public AForm {

public:

	explicit					RobotomyRequestForm( const std::string & target );
								RobotomyRequestForm( const RobotomyRequestForm & other );
								~RobotomyRequestForm( );
	RobotomyRequestForm &		operator=( const RobotomyRequestForm & rhs );

	virtual void				executeConcrete( const Bureaucrat & executor ) const;

private:

								RobotomyRequestForm( );

};

#endif
