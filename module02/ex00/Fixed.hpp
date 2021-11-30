#pragma once

#include <iostream>
#include <string>

class Fixed
{
private:
	static int const	_fractionalBitsNb;

	int					_rawBits;
public:
	Fixed(void);
	Fixed(Fixed &src);
	~Fixed();

	void	setRawBits(int raw);
	int		getRawBits(void);
	
	Fixed	&operator=(Fixed &rhs);
};
