#ifndef WEAPON_H
# define WEAPON_H

class Weapon {

public:

	const std::string & getType( ) const;
	void				setType( std::string const & type );

	explicit			Weapon( std::string const & type );
						Weapon( );
						~Weapon( );
						Weapon( const Weapon & src );
						Weapon & operator=( Weapon const & rhs);

private:

	std::string			_type;

};

#endif
