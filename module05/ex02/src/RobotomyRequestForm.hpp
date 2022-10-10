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


private:

	virtual void				executeConcrete( ) const;
								RobotomyRequestForm( );

};

#endif
