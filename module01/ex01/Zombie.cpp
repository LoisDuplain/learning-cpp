#include "Zombie.hpp"

Zombie::Zombie()
{
	
}

Zombie::Zombie(std::string name) : _name(name)
{
	
}

Zombie::~Zombie()
{
	std::cout << "<" << _name << "> NOOOO ! I've been deleted !" << std::endl;
}

void	Zombie::announce()
{
	std::cout << "<" << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::get_name()
{
	return this->_name;
}
void		Zombie::set_name(std::string name)
{
	this->_name = name;
}