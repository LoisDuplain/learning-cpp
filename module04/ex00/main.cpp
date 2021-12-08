#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	std::cout << "--- Create ---" << std::endl;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	std::cout << "--- Types ---" << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	
	std::cout << "--- Sound ---" << std::endl;
	meta->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << "--- Delete ---" << std::endl;
	delete meta;
	delete dog;
	delete cat;

	std::cout << std::endl << std::endl;

	std::cout << "--- Wrong Create ---" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();	
	
	std::cout << "--- Wrong Types ---" << std::endl;
	std::cout << wrongMeta->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	
	std::cout << "--- Wrong Sound ---" << std::endl;
	wrongMeta->makeSound();
	wrongCat->makeSound();

	std::cout << "--- Wrong Delete ---" << std::endl;
	delete wrongMeta;
	delete wrongCat;

	return (0);
}