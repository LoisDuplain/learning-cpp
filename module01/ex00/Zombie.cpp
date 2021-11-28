#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "<" << _name << "> I'm happy to be here !" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "<" << _name << "> NOOOO ! I've been deleted !" << std::endl;
}

void	Zombie::announce()
{
	std::cout << "<" << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}