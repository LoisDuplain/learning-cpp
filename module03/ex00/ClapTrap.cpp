#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Unknown"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap <" << _name << "> Hey ! I'm " << _name << std::endl; 
}
ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap <" << _name << "> Hey ! I'm " << _name << std::endl; 
}
ClapTrap::ClapTrap(ClapTrap const &src)
{
	*this = src;
	std::cout << "ClapTrap <" << _name << "> Hey ! I'm " << _name << std::endl; 
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap <" << _name << "> I've been killed" << std::endl; 
}

void	ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap <" << _name << "> I attack " << target << " (causing " << _attack_damage << " points of damage)" << std::endl;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap <" << _name << "> I took " << amount << " points of damage" << std::endl;
	if (amount > )
}

std::string		ClapTrap::getName(void)	const
{
	return this->_name;
}
void			ClapTrap::setName(std::string const name)
{
	this->_name = name;
}
unsigned int	ClapTrap::getHitPoints(void)	const
{
	return this->_hit_points;
}
void			ClapTrap::setHitPoints(unsigned int hit_points)
{
	this->_hit_points = hit_points;
}
unsigned int	ClapTrap::getEnergyPoints(void)	const
{
	return this->_energy_points;
}
void			ClapTrap::setEnergyPoints(unsigned int energy_points)
{
	this->_energy_points = energy_points;
}
unsigned int	ClapTrap::getAttackDamage(void)	const
{
	return this->_attack_damage;
}
void			ClapTrap::setAttackDamage(unsigned int attack_damage)
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
