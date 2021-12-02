#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "- Ex 00 -----------------------------------------" << std::endl;
	ClapTrap	unknownClap;
	ClapTrap	bobby("Bobby");

	ClapTrap	timmy("Timmy");
	timmy.setAttackDamage(50);

	std::cout << "Unknown clap: " << unknownClap << std::endl;
	std::cout << "Bobby clap: " << bobby << std::endl;
	std::cout << "Timmy clap: " << timmy << std::endl;

	bobby.attack(timmy.getName());
	timmy.takeDamage(bobby.getAttackDamage());
	
	timmy.attack(bobby.getName());
	bobby.takeDamage(timmy.getAttackDamage());

	timmy.beRepaired(42);
	timmy.beRepaired(UINT_MAX);

	std::cout << std::endl << "- Ex 01 -----------------------------------------" << std::endl;

	ScavTrap	unknownScav;
	ScavTrap	jimmy("Jimmy");

	std::cout << "Unknown scav: " << unknownScav << std::endl;
	std::cout << "Jimmy scav: " << jimmy << std::endl;

	jimmy.guardGate();
	jimmy.attack(bobby.getName());

	unknownScav = jimmy;
	std::cout << "Unknown scav: " << unknownScav << std::endl;


	std::cout << std::endl << "-  End  -----------------------------------------" << std::endl;
}