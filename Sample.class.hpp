#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample1 {

	public:

		char	a1;
		int		a2;
		float	a3;
		float const pi;
		int		qd;


		Sample1( float const f );
		~Sample1( void );

		void bar( void ) const;


	private:

	int		_privateFoo;

	void	_privateBar( void ) const;




};

#endif // SAMPLE_CLASS_H