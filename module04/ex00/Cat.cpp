#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat | " << _type << " animal created" << std::endl;
}
Cat::Cat(Cat const &src)
{
	*this = src;
	std::cout << "Cat | " << _type << " animal created by copy" << std::endl;
}
Cat::~Cat()
{
	std::cout << "Cat | " << _type << " animal deleted" << std::endl;
}

void	Cat::makeSound()	const
{
	std::cout << "Cat | Meowed" << std::endl;
}

Cat		&Cat::operator=(Cat const &o)
{
	_type = o._type;
	return *this;
}