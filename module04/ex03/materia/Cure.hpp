#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(Cure const &src);
	virtual ~Cure();

	AMateria	*clone() const;
	void		use(ICharacter &target);

	Cure	&operator=(Cure const &src);
};