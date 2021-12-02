#pragma once

#include <iostream>

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &src);
	~ScavTrap();

	void	attack(std::string const &target);

	void	guardGate(void);

	ScavTrap	&operator=(ScavTrap const &src);
};
