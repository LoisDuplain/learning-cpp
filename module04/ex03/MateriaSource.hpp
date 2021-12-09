#pragma once

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*_inventory[4];
public:
	MateriaSource();
	MateriaSource(MateriaSource const &src);
	virtual ~MateriaSource();

	void		learnMateria(AMateria *);
	AMateria	*createMateria(std::string const &type);

	MateriaSource	&operator=(MateriaSource const &src);
};