#ifndef HUMANB_H
# define HUMANB_H

# ifndef nullptr

const                         /* this is a const object...     */
class nullptr_t
{
public:
   template<class T>          /* convertible to any type       */
   operator T*() const        /* of null non-member            */
      { return 0; }           /* pointer...                    */

   template<class C, class T> /* or any type of null           */
      operator T C::*() const /* member pointer...             */
      { return 0; }   

private:
   void operator&() const;    /* Can't take address of nullptr */
} nullptr = {};               /* and whose name is nullptr     */


# endif

# include <iostream>
# include <sstream>
# include "Weapon.hpp"

class HumanB {

public:

	std::string			getName( ) const;
	void				setWeapon( Weapon & weapon );

	std::string			name;
	Weapon *			weapon;

	explicit			HumanB( std::string name );
						HumanB( );
						~HumanB( );
						HumanB( const HumanB & src );
						HumanB & operator=( const HumanB & rhs);

	void				attack( ) const;

private:

	static int			_nb_humanAs_alive;

};

std::ostream &operator<<(std::ostream& o_stream, HumanB & rhs);

#endif
