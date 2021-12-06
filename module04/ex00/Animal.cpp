#include "Animal.hpp"

Animal::Animal(void)	:	_type("Unknown")
{
	std::cout << _type << " animal created" << std::endl;
}
Animal::Animal(std::string const type)	:	_type(type)
{
	std::cout << _type << " animal created" << std::endl;
}
Animal::Animal(Animal const &src)
{
	*this = src;
	std::cout << _type << " animal created by copy" << std::endl;
}
Animal::~Animal(void)
{
	std::cout << _type << " animal deleted" << std::endl;
}

std::string	Animal::getType(void)	const
{
	return _type;
}
void		Animal::setType(std::string const type)
{
	_type = type;
}

Animal	&Animal::operator=(Animal const &o)
{
	_type = o._type;
	return *this;
}