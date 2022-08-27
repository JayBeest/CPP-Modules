#ifndef BUROCRAT_H
# define BUROCRAT_H

class Burocrat {

public:

	std::string			getName( ) const;
	unsigned int		getGrade( ) const;

	explicit			Burocrat( const std::string & name, unsigned int grade );
						Burocrat( );
						Burocrat( const Burocrat & src );
						~Burocrat( );
						Burocrat & operator=( const Burocrat & rhs);

	void				incrGrade( void );
	void				decrGrade( void );

	void				GradeTooHighException()

	static void			makeSilent( void );

private:

	const std::string	_name;
	unsigned int		_grade;

	static bool		_loud;

};

#endif
