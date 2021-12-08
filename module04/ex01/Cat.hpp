#pragma once

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain*	_brain;

public:
	Cat(void);
	Cat(Cat const &src);
	virtual ~Cat();

	void virtual	makeSound()	const;

	const Brain	*getBrain() const;

	Cat		&operator=(Cat const &o);
};