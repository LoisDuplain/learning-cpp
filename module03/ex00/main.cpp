#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	unknown;
	ClapTrap	bobby("Bobby");

	ClapTrap	timmy("Timmy");
	timmy.setAttackDamage(50);

	std::cout << unknown << std::endl;
	std::cout << bobby << std::endl;
	std::cout << timmy << std::endl;

	bobby.attack(timmy.getName());
	timmy.takeDamage(bobby.getAttackDamage());
	
	timmy.attack(bobby.getName());
	bobby.takeDamage(timmy.getAttackDamage());

	timmy.beRepaired(42);
	timmy.beRepaired(UINT_MAX);
}