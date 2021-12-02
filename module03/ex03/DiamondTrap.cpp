#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : _name("Unknown")
{
	ClapTrap::setName(_name + "_clap_name");
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 30;
	std::cout << "DiamondTrap <" << _name << "> Hey ! I'm " << _name << std::endl; 
}
DiamondTrap::DiamondTrap(std::string name) : _name(name)
{
	ClapTrap::setName(_name + "_clap_name");
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 30;
	std::cout << "DiamondTrap <" << _name << "> Hey ! I'm " << _name << std::endl; 
}
DiamondTrap::DiamondTrap(DiamondTrap const &src)
{
	*this = src;
	std::cout << "DiamondTrap <" << _name << "> Hey ! I'm " << _name << std::endl; 
}
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap <" << _name << "> I've been killed" << std::endl; 
}

void	DiamondTrap::whoAmI(void)
{
	std::cout
	<<	"Who Am I ??? "
	<< "{name: " << _name
	<< ", clap_name: " << ClapTrap::_name
	<< "}"
	<<	std::endl;
}

std::string		DiamondTrap::getName(void)	const
{
	return this->_name;
}
void			DiamondTrap::setName(std::string const name)
{
	this->_name = name;
}

DiamondTrap		&DiamondTrap::operator=(DiamondTrap const &src)
{
	_name = src._name;
	ClapTrap::setName(src._name + "_clap_name");
	_hit_points = src._hit_points;
	_energy_points = src._energy_points;
	_attack_damage = src._attack_damage;
	return (*this);
}

std::ostream	&operator<<(std::ostream &ostream, DiamondTrap const &o)
{
	ostream
	<< "{name: " << o.getName()
	<< ", hit_points: " << o.getHitPoints()
	<< ", energy_points: " << o.getEnergyPoints()
	<< ", attack_damage: " << o.getAttackDamage()
	<< "}";
	return ostream;
}
