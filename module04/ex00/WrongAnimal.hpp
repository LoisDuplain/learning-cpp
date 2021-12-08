#pragma once

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const &src);
		~WrongAnimal();

		void	makeSound()	const;

		std::string	getType() const;

		WrongAnimal	&operator=(WrongAnimal const &o);
};