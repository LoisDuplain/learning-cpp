#pragma once

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain*	_brain;

public:
	Dog(void);
	Dog(Dog const &src);
	virtual ~Dog();

	void virtual	makeSound()	const;

	const Brain	*getBrain() const;

	Dog		&operator=(Dog const &o);
};
