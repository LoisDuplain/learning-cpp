#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap <" << _name << "> Hey ! I'm " << _name << std::endl; 
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap <" << _name << "> Hey ! I'm " << _name << std::endl; 
}
ScavTrap::ScavTrap(ScavTrap const &src)
{
	*this = src;
	std::cout << "ScavTrap <" << _name << "> Hey ! I'm " << _name << std::endl; 
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap <" << _name << "> I've been killed" << std::endl; 
}

void	ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap <" << _name << "> I attack " << target << " (causing " << _attack_damage << " points of damage)" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap <" << _name << "> I enterred in gate keeper mode" << std::endl; 
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &src)
{
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	return (*this);
}
