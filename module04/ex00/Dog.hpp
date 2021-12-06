#pragma once

#include <iostream>

class Dog
{
public:
	Dog(void);
	Dog(Dog const &src);
	~Dog();

	

	Dog	&operator=(Dog const &src);
};
