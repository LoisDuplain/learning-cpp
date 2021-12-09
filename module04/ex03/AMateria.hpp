#pragma once

#include <iostream>

#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string	_type;

public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(AMateria const &src);
	virtual	~AMateria();

	virtual AMateria	*clone() const = 0;
	virtual void		use(ICharacter &target);

	std::string const	&getType() const;

	AMateria	&operator=(AMateria const &src);
};
