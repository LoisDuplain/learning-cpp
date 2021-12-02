#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap <" << _name << "> Hey ! I'm " << _name << std::endl; 
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap <" << _name << "> Hey ! I'm " << _name << std::endl; 
}
FragTrap::FragTrap(FragTrap const &src)
{
	*this = src;
	std::cout << "FragTrap <" << _name << "> Hey ! I'm " << _name << std::endl; 
}
FragTrap::~FragTrap()
{
	std::cout << "FragTrap <" << _name << "> I've been killed" << std::endl; 
}

void	FragTrap::attack(std::string const &target)
{
	std::cout << "FragTrap <" << _name << "> I attack " << target << " (causing " << _attack_damage << " points of damage)" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap <" << _name << "> Give me a high five !" << std::endl; 
}
