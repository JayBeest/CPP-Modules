#ifndef FORM_H
# define FORM_H

class Bureaucrat;

class Form {

public:

	std::string			getName( ) const;
	bool				getSigned( ) const;
	unsigned int		getRequiredGrade( ) const;
	unsigned int		getExecGrade( ) const;
	std::string			getTarget( ) const;

	explicit			Form( const std::string & name, const std::string & target, const unsigned int & req_grade, const unsigned int & exec_grade );
						Form( );
						Form( const Form & other );
						~Form( );
	Form &				operator=( const Form & rhs );

	void				beSigned( const Bureaucrat & bureaucrat );

	static void			makeSilent( void );

	class GradeTooHighException : public std::runtime_error {

	public:
		explicit GradeTooHighException( std::string msg = "grade is too high" )
				: std::runtime_error(msg) {};
	};

	class GradeTooLowException : public std::exception {

	public:
		virtual const char * what() const _NOEXCEPT {
			return ("grade is too low");
		}
	};

private:

	const std::string	_name;
	const std::string	_target;
	const unsigned int	_required_grade;
	const unsigned int	_exec_grade;
	bool				_signed;


protected:

	static bool			_loud;

};

std::ostream &	operator<<( std::ostream & o_stream, const Form & form );

#endif
