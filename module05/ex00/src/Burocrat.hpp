#ifndef BUROCRAT_H
# define BUROCRAT_H

# include <stdexcept>

class Burocrat {

public:

	std::string			getName( void ) const;
	unsigned int		getGrade( void ) const;

	explicit			Burocrat( const std::string & name, unsigned int grade );
						Burocrat( );
						Burocrat( const Burocrat & src );
						~Burocrat( );
						Burocrat & operator=( const Burocrat & rhs );

	void				incrGrade( void );
	void				decrGrade( void );

    class GradeTooHighException : public std::runtime_error {
    public:
        explicit GradeTooHighException(const std::string & msg="Grade is too high (< 1)")
        : std::runtime_error(msg) {};
        virtual const char * what() const throw() {
            return ("Grade is too high (< 1) but from the what() funct");
        }
    };

    class GradeTooLowException : public std::exception {
    public: virtual const char * what() const throw() {
            return ("Grade is too low (> 150)");
        }
    };

	static void			makeSilent( void );

private:

	const std::string	_name;
	unsigned int		_grade;

	static bool         _loud;

};

#endif
