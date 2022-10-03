#ifndef FORM_H
# define FORM_H

# include <iostream>

class Form {

public:

	std::string			getName( ) const;
	bool				getSigned( ) const;
	unsigned int		getRequiredGrade( ) const;

	explicit			Form( const std::string & name, const unsigned int & required_grade );
						Form( );
						Form( const Form & other );
						~Form( );
	Form &				operator=( const Form & rhs );

	void				doStuff() const;

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
	bool				_signed;
	const unsigned int	_required_grade;

	static bool			_loud;

};

std::ostream &	operator<<( std::ostream & o_stream, const Form & form );

#endif
