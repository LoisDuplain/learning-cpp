#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	std::cout << std::endl << "--- Ex02 ----------------------------" << std::endl;

	const AAnimal	*Aanimals[4];
	
	std::cout << "Creating\n";
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			Aanimals[i] = new Cat();
		else
		 	Aanimals[i] = new Dog();
	}

	std::cout << "\nTesting assignation operator\n";
	const AAnimal	*Aanimal = Aanimals[0];
	std::cout << "AAnimal assignated type: " << Aanimal->getType() << std::endl;
	Aanimal->makeSound();
	
	const AAnimal	*Aanimal2 = Aanimals[2];
	std::cout << "AAnimal2 assignated type: " << Aanimal2->getType() << std::endl;
	Aanimal2->makeSound();

	std::cout << "\nTesting copies\n\n";

	std::cout << "\n- Original\n\n";
	Cat *cat = new Cat();
	std::cout << "Original cat sound: ";
	cat->makeSound();
	std::cout << "Original cat brain idea: -" << cat->getBrain()->_ideas[0] << "-" << std::endl;
	
	std::cout << "\n- Copy\n\n";
	Cat *cpy_cat = new Cat(*cat);
	std::cout << "Copied cat sound: ";
	cpy_cat->makeSound();
	std::cout << "Copied cat brain idea: -" << cpy_cat->getBrain()->_ideas[0] << "-" << std::endl;
	
	delete cat;
	delete cpy_cat;

	std::cout << "\nDeleting\n";
	for (int i = 0; i < 4; i++)
		delete Aanimals[i];

	return (0);
}