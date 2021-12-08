#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"),	_brain(new Brain())
{
	for (size_t i = 0; i < 100; i++)
		_brain->_ideas[i] = "Dog idea";
	std::cout << "Dog | " << _type << " animal created" << std::endl;
}
Dog::Dog(Dog const &src) : Animal("Cat"), _brain(NULL)
{
	*this = src;
	std::cout << "Dog | " << _type << " animal created by copy" << std::endl;
}
Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog | " << _type << " animal deleted" << std::endl;
}

void	Dog::makeSound()	const
{
	std::cout << "Dog | Barked" << std::endl;
}

const Brain	*Dog::getBrain() const
{
	return _brain;
}

Dog		&Dog::operator=(Dog const &o)
{
	if (_brain)
		delete _brain;
	_brain = new Brain();
	for (int i = 0; i < 100; i++)
		_brain->_ideas[i] = o._brain->_ideas[i];
	_type = o._type;
	return *this;
}