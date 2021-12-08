#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	std::cout << std::endl << "--- Ex01 ----------------------------" << std::endl;

	const Animal	*animals[4];
	
	std::cout << "Creating\n";
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			animals[i] = new Cat();
		else
		 	animals[i] = new Dog();
	}

	std::cout << "\nTesting assignation operator\n";
	const Animal	*animal = animals[0];
	std::cout << "Animal assignated type: " << animal->getType() << std::endl;
	animal->makeSound();
	
	const Animal	*animal2 = animals[2];
	std::cout << "Animal2 assignated type: " << animal2->getType() << std::endl;
	animal2->makeSound();

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
		delete animals[i];

	return (0);
}