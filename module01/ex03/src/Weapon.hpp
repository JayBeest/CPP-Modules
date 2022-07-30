#ifndef WEAPON_H
# define WEAPON_H

class Weapon {

public:

	const std::string & getType( ) const;
	void				setType( std::string type );

						Weapon( std::string type );
						Weapon( );
						~Weapon( );
						Weapon( const Weapon & src );
						Weapon & operator=( const Weapon & rhs);

private:

	std::string			_type;

};

#endif
