#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog | " << _type << " animal created" << std::endl;
}
Dog::Dog(Dog const &src)
{
	*this = src;
	std::cout << "Dog | " << _type << " animal created by copy" << std::endl;
}
Dog::~Dog()
{
	std::cout << "Dog | " << _type << " animal deleted" << std::endl;
}

void	Dog::makeSound()	const
{
	std::cout << "Dog | Barked" << std::endl;
}

Dog		&Dog::operator=(Dog const &o)
{
	_type = o._type;
	return *this;
}