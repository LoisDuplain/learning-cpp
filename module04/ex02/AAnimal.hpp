#pragma once

#include <iostream>

class AAnimal
{
protected:
	std::string	_type;

public:
	virtual	~AAnimal();

	void virtual	makeSound(void)	const = 0;

	std::string	getType(void)	const;

	AAnimal		&operator=(AAnimal const &o);
};
