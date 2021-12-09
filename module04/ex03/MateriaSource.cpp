#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}
MateriaSource::MateriaSource(MateriaSource const &src)
{
	*this = src;
}
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = materia;
			break;
		}
	}
}
AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i] && _inventory[i]->getType() == type)
			return _inventory[i]->clone();
	return NULL;
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &src)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = src._inventory[i];
	return *this;
}
