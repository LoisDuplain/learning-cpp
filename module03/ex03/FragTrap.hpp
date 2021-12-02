#pragma once

#include <iostream>

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(FragTrap const &stc);
	~FragTrap();

	void	attack(std::string const &target);

	void	highFivesGuys(void);

	FragTrap	&operator=(FragTrap const &src);
};
