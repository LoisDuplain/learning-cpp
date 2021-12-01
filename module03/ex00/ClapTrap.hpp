#pragma once

#include <iostream>

class ClapTrap
{
private:
	std::string	_name;
	int			_hit_points;
	int			_energy_points;
	int			_attack_damage;
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
	int				getHitPoints(void)		const;
	void			setHitPoints(const int hit_points);
	int				getEnergyPoints(void)	const;
	void			setEnergyPoints(const int energy_points);
	int				getAttackDamage(void)	const;
	void			setAttackDamage(const int attack_damage);

	ClapTrap		&operator=(ClapTrap const &o);
};

std::ostream	&operator<<(std::ostream &ostream, ClapTrap const &o);
