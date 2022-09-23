#ifndef WEAPON_H
# define WEAPON_H

class Weapon {

public:

	const std::string & getType( ) const;
	void				setType( const std::string & type );

	explicit			Weapon( const std::string & type );
						Weapon( );
						~Weapon( );
						Weapon( const Weapon & other );
	Weapon &			operator=( const Weapon & rhs );

private:

	std::string			_type;

};

#endif
