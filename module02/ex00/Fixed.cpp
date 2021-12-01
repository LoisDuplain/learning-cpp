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
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits(int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = raw;
}
int		Fixed::getRawBits(void)	const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

Fixed	&Fixed::operator=(Fixed const &f)
{
	std::cout << "Assignation operator called" << std::endl;
	_rawBits = f._rawBits;
	return (*this);
}
