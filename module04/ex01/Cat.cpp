#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat"),	_brain(new Brain())
{
	for (size_t i = 0; i < 100; i++)
		_brain->_ideas[i] = "Cat idea";
	std::cout << "Cat | " << _type << " animal created" << std::endl;
}
Cat::Cat(Cat const &src) : Animal("Cat"), _brain(NULL)
{
	*this = src;
	std::cout << "Cat | " << _type << " animal created by copy" << std::endl;
}
Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat | " << _type << " animal deleted" << std::endl;
}

void	Cat::makeSound()	const
{
	std::cout << "Cat | Meowed" << std::endl;
}

const Brain	*Cat::getBrain() const
{
	return _brain;
}

Cat		&Cat::operator=(Cat const &o)
{
	if (_brain)
		delete _brain;
	_brain = new Brain();
	for (int i = 0; i < 100; i++)
		_brain->_ideas[i] = o._brain->_ideas[i];
	_type = o._type;
	return *this;
}