#pragma once

#include <iostream>

class ClapTrap
{
private:
	std::string		_name;
	unsigned int	_hit_points;
	unsigned int	_energy_points;
	unsigned int	_attack_damage;
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &src);
	~ClapTrap();

	void	attack(std::string const &target);
	void	takeDamage(unsigned int amout);
	void	beRepaired(unsigned int amout);

	std::string		getName(void)			const;
	void			setName(const std::string name);
	unsigned int	getHitPoints(void)		const;
	void			setHitPoints(unsigned int hit_points);
	unsigned int	getEnergyPoints(void)	const;
	void			setEnergyPoints(unsigned int energy_points);
	unsigned int	getAttackDamage(void)	const;
	void			setAttackDamage(unsigned int attack_damage);

	ClapTrap		&operator=(ClapTrap const &o);
};

std::ostream	&operator<<(std::ostream &ostream, ClapTrap const &o);
