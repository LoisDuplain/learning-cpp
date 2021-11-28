#include "Zombie.hpp"

int	main(void)
{
	randomChump("Henri Paul");

	Zombie	*zombie1 = newZombie("Sacha");
	Zombie	*zombie2 = newZombie("Jeremie");
	Zombie	*zombie3 = newZombie("Ludwig");

	zombie1->announce();

	randomChump("Steve Jobs");

	zombie2->announce();

	randomChump("Orelsan");

	zombie3->announce();

	delete zombie3;
	delete zombie2;
	delete zombie1;
	return (0);
}