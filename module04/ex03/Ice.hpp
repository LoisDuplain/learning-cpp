#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(Ice const &src);
	virtual ~Ice();

	AMateria	*clone() const;
	void		use(ICharacter &target);

	Ice		&operator=(Ice const &src);
};