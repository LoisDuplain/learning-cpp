#include "Fixed.hpp"

int const	Fixed::_fractionalBitsNb = 8;

Fixed		&Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 <= f2)
		return f1;
	return f2;
}
const Fixed	&Fixed::min(Fixed const &f1, Fixed const &f2)
{
	if (f1 <= f2)
		return f1;
	return f2;
}
Fixed		&Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 >= f2)
		return f1;
	return f2;
}
const Fixed	&Fixed::max(Fixed const &f1, Fixed const &f2)
{
	if (f1 >= f2)
		return f1;
	return f2;
}

Fixed::Fixed(void) : _rawBits(0)
{
}
Fixed::Fixed(Fixed const &src)
{
	*this = src;
}
Fixed::Fixed(int intNumber) : _rawBits(intNumber << _fractionalBitsNb)
{
}
Fixed::Fixed(float floatNumber) : _rawBits(roundf(floatNumber * (1 << _fractionalBitsNb)))
{
}
Fixed::~Fixed()
{
}

int		Fixed::toInt(void) const
{
	return (_rawBits >> _fractionalBitsNb);
}
float	Fixed::toFloat(void) const
{
	return ((float)_rawBits / (1 << _fractionalBitsNb));
}

void	Fixed::setRawBits(int raw)
{
	_rawBits = raw;
}
int		Fixed::getRawBits(void) const
{
	return (_rawBits);
}

Fixed	&Fixed::operator=(Fixed const &f)
{
	_rawBits = f.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &f) const
{
	Fixed	tmp;

	tmp._rawBits = _rawBits + f._rawBits;
	return tmp;
}
Fixed	Fixed::operator-(Fixed const &f) const
{
	Fixed	tmp;

	tmp._rawBits = _rawBits - f._rawBits;
	return tmp;
}
Fixed	Fixed::operator*(Fixed const &f) const
{
	Fixed	tmp;

	tmp._rawBits = _rawBits * f._rawBits / (1 << _fractionalBitsNb);
	return tmp;
}
Fixed	Fixed::operator/(Fixed const &f) const
{
	Fixed	tmp;

	tmp._rawBits = _rawBits / f._rawBits * (1 << _fractionalBitsNb);
	return tmp;
}

Fixed	&Fixed::operator++()
{
	_rawBits++;
	return *this;
}
Fixed	Fixed::operator++(int)
{
	Fixed old = *this;
	_rawBits++;
	return old;
}
Fixed	&Fixed::operator--()
{
	_rawBits--;
	return *this;
}
Fixed	Fixed::operator--(int)
{
	Fixed old = *this;
	_rawBits--;
	return old;
}

bool	Fixed::operator>(Fixed const &f) const
{
	return _rawBits > f._rawBits;
}
bool	Fixed::operator<(Fixed const &f) const
{
	return _rawBits < f._rawBits;
}
bool	Fixed::operator>=(Fixed const &f) const
{
	return _rawBits >= f._rawBits;
}
bool	Fixed::operator<=(Fixed const &f) const
{
	return _rawBits <= f._rawBits;
}
bool	Fixed::operator==(Fixed const &f) const
{
	return _rawBits == f._rawBits;
}
bool	Fixed::operator!=(Fixed const &f) const
{
	return _rawBits != f._rawBits;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &f)
{
	o << f.toFloat();
	return o;
}
