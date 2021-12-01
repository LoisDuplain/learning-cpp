#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	unknown;
	ClapTrap	bobby("Bobby");
	ClapTrap	timmy("Timmy");

	std::cout << unknown << std::endl;
	std::cout << bobby << std::endl;
	std::cout << timmy << std::endl;
}