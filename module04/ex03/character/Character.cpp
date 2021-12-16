/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:08:56 by lwourms           #+#    #+#             */
/*   Updated: 2021/12/09 12:50:12 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _name("Default")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}
Character::Character(std::string const &name): _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}
Character::Character(Character const &src)
{
	*this = src;
}
Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i] != NULL)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			break ;
		}
}
void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return;
	_inventory[idx] = NULL;
}
void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
		return;
	if (_inventory[idx] != NULL)
		_inventory[idx]->use(target);
}

std::string const &Character::getName() const
{
	return _name;
}
AMateria 	*(&Character::getInventory())[4]
{
	return _inventory;
}

Character	&Character::operator=(Character const &src)
{
	_name = src._name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = src._inventory[i];
	return *this;
}
