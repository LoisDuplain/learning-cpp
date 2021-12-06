#pragma once

#include <iostream>

class Animal
{
protected:
	std::string	_type;

private:
	Animal(void);

public:
	Animal(std::string const type);
	Animal(Animal const &src);
	~Animal();

	void virtual	makeSound(void);

	std::string	getType(void)	const;
	void		setType(std::string const type);

	Animal		&operator=(Animal const &o);
};
