#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
private:
	static int const	_fractionalBitsNb;

	int					_rawBits;
public:
	Fixed(void);
	Fixed(Fixed const &src);
	Fixed(int intNumber);
	Fixed(float floatNumber);
	~Fixed();

	int		toInt(void) const;
	float	toFloat(void) const;

	void	setRawBits(int raw);
	int		getRawBits(void) const;
	
	Fixed	&operator=(Fixed const &f);
};

std::ostream &operator<<(std::ostream &o, Fixed const &f);
