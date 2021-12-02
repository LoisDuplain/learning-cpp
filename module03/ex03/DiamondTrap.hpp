#pragma once

#include <iostream>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _name;
public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const &src);
	~DiamondTrap();

	using	ScavTrap::attack;
	void	whoAmI(void);

	std::string		getName(void)			const;
	void			setName(const std::string name);

	DiamondTrap		&operator=(DiamondTrap const &src);
};

std::ostream	&operator<<(std::ostream &ostream, DiamondTrap const &o);
