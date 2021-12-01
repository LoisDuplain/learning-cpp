#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Unknown"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
}
ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
}
ClapTrap::ClapTrap(ClapTrap const &src)
{
	*this = src;
}
ClapTrap::~ClapTrap()
{
}

void	ClapTrap::attack(std::string const &target)
{
	std::cout << "<" << _name << "> I attack " << target << " (causing " << _attack_damage << " points of damage)" << std::endl;
}

std::string	ClapTrap::getName(void)	const
{
	return this->_name;
}
void		ClapTrap::setName(std::string const name)
{
	this->_name = name;
}
int			ClapTrap::getHitPoints(void)	const
{
	return this->_hit_points;
}
void		ClapTrap::setHitPoints(int const hit_points)
{
	this->_hit_points = hit_points;
}
int			ClapTrap::getEnergyPoints(void)	const
{
	return this->_energy_points;
}
void		ClapTrap::setEnergyPoints(int const energy_points)
{
	this->_energy_points = energy_points;
}
int			ClapTrap::getAttackDamage(void)	const
{
	return this->_attack_damage;
}
void		ClapTrap::setAttackDamage(int const attack_damage)
{
	this->_attack_damage = attack_damage;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &o)
{
	this->_name = o._name;
	this->_hit_points = o._hit_points;
	this->_energy_points = o._energy_points;
	this->_attack_damage = o._attack_damage;
	return (*this);
}

std::ostream	&operator<<(std::ostream &ostream, ClapTrap const &o)
{
	ostream
	<< "{name: " << o.getName()
	<< ", hit_points: " << o.getHitPoints()
	<< ", energy_points: " << o.getEnergyPoints()
	<< ", attack_damage: " << o.getAttackDamage()
	<< "}";
	return ostream;
}
