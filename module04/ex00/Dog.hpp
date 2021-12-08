#pragma once

#include <iostream>

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog(void);
	Dog(Dog const &src);
	virtual ~Dog();

	void virtual	makeSound()	const;

	Dog		&operator=(Dog const &o);
};
