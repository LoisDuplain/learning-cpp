#pragma once

#include <iostream>

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter
{
private:
	std::string	_name;
	AMateria	*_inventory[4];

public:
	Character();
	Character(std::string const &name);
	Character(Character const &src);
	virtual ~Character();

	void		equip(AMateria *m);
	void		unequip(int idx);
	void		use(int idx, ICharacter &target);

	std::string const	&getName() const;
	AMateria			*(&getInventory())[4];

	Character	&operator=(Character const &src);
};