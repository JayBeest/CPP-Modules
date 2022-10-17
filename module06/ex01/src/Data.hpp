#ifndef DATA_H
# define DATA_H

class Data {

public:

	int				getData( ) const;
	void			setData( const int & data );

					Data( );
					Data( const Data & other );
					~Data( );
	Data &			operator=( const Data & rhs );

private:

	int				_data;

};

#endif
