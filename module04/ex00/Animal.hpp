#pragma once

#include <iostream>

class Animal
{
protected:
	std::string	_type;

public:
	Animal(void);
	Animal(std::string const type);
	Animal(Animal const &src);
	virtual	~Animal();

	void virtual	makeSound(void)	const;

	std::string	getType(void)	const;

	Animal		&operator=(Animal const &o);
};
