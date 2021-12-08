#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat | " << _type << " wrong animal created" << std::endl;
}
WrongCat::WrongCat(WrongCat const &src)
{
	*this = src;
	std::cout << "WrongCat | " << _type << " wrong animal created by copy" << std::endl;
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat | " << _type << " wrong animal deleted" << std::endl;
}

void	WrongCat::makeSound()	const
{
	std::cout << "WrongCat | Meowed" << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &o)
{
	_type = o._type;
	return *this;
}