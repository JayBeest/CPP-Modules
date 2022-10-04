#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <stdexcept>
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat {

public:

	std::string			getName( void ) const;
	unsigned int		getGrade( void ) const;

	explicit			Bureaucrat( const std::string & name, unsigned int grade );
						Bureaucrat( );
						Bureaucrat( const Bureaucrat & other );
						~Bureaucrat( );
	Bureaucrat &		operator=( const Bureaucrat & rhs );

	void				incrGrade( void );
	void				decrGrade( void );
	void				signForm( Form & form );

	static void			makeSilent( void );

	class GradeTooHighException : public std::runtime_error {

    public:
        explicit GradeTooHighException(std::string msg="Grade is too high (< 1)")
        : std::runtime_error(msg) {};
    };

	class GradeTooLowException : public std::exception {

    public:
		virtual const char * what() const throw() {
            return ("Grade is too low (> 150)");
        }
    };

private:

	const std::string	_name;
	unsigned int		_grade;

	static bool         _loud;

};

std::ostream & operator<<( std::ostream & o_stream, const Bureaucrat & bureaucrat );

#endif
