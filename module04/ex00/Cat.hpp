#pragma once

#include <iostream>

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(Cat const &src);
	virtual ~Cat();

	void virtual	makeSound()	const;

	Cat		&operator=(Cat const &o);
};