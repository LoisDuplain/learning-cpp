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
	static		 Fixed	&min(Fixed &f1, Fixed &f2);
	static const Fixed	&min(Fixed const &f1, Fixed const &f2);
	static 		 Fixed	&max(Fixed &f1, Fixed &f2);
	static const Fixed	&max(Fixed const &f1, Fixed const &f2);

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

	Fixed	operator+(Fixed const &f) const;
	Fixed	operator-(Fixed const &f) const;
	Fixed	operator*(Fixed const &f) const;
	Fixed	operator/(Fixed const &f) const;

	Fixed	&operator++();
	Fixed	operator++(int);
	Fixed	&operator--();
	Fixed	operator--(int);
	
	bool	operator>(Fixed const &f) const;
	bool	operator<(Fixed const &f) const;
	bool	operator>=(Fixed const &f) const;
	bool	operator<=(Fixed const &f) const;
	bool	operator==(Fixed const &f) const;
	bool	operator!=(Fixed const &f) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &f);
