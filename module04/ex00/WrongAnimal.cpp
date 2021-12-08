#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)	:	_type("WrongUnknown")
{
	std::cout << "WrongAnimal | " << _type << " wrong animal created" << std::endl;
}
WrongAnimal::WrongAnimal(std::string type)	:	_type(type)
{
	std::cout << "WrongAnimal | " << _type << " wrong animal created" << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	*this = src;
	std::cout << "WrongAnimal | " << _type << " wrong animal created by copy" << std::endl;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal | " << _type << " wrong animal deleted" << std::endl;
}

void	WrongAnimal::makeSound()	const
{
	std::cout << "WrongAnimal | Made sound" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return _type;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &o)
{
	_type = o._type;
	return *this;
}