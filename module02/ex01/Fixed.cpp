#include "Fixed.hpp"

int const	Fixed::_fractionalBitsNb = 8;

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}
Fixed::Fixed(int intNumber) : _rawBits(intNumber << _fractionalBitsNb)
{
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(float floatNumber) : _rawBits(roundf(floatNumber * (1 << _fractionalBitsNb)))
{
	std::cout << "Float constructor called" << std::endl;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::toInt(void) const
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
	std::cout << "Assignation operator called" << std::endl;
	_rawBits = f.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &f)
{
	o << f.toFloat();
	return o;
}
