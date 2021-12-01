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
	Fixed(Fixed const &src);
	~Fixed();

	void	setRawBits(int const raw);
	int		getRawBits(void)	const;
	
	Fixed	&operator=(Fixed const &f);
};
