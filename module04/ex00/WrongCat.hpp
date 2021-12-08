#pragma once

#include <iostream>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(WrongCat const &src);
	~WrongCat();

	void	makeSound()	const;

	WrongCat	&operator=(WrongCat const &o);
};