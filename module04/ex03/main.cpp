#include <iostream>

#include "materia/Ice.hpp"
#include "materia/Cure.hpp"
#include "character/Character.hpp"
#include "materia/source/MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter*	me = new Character("me");
	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");

	std::cout << "--------------------" << std::endl;
	std::cout << "Me attacking Bob" << std::endl;
	std::cout << "--------------------" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "--------------------" << std::endl << std::endl;
	
	std::cout << "--------------------" << std::endl;
	std::cout << "Bob attacking Me" << std::endl;
	std::cout << "--------------------" << std::endl;
	bob->use(0, *me);
	std::cout << "--------------------" << std::endl;
	bob->equip(new Ice());
	bob->use(0, *me);
	std::cout << "--------------------" << std::endl << std::endl;

	std::cout << "--------------------" << std::endl;
	std::cout << "Deep copying Bob" << std::endl;
	std::cout << "--------------------" << std::endl;
	ICharacter*	copiedBob = new Character(*(Character *)bob);
	copiedBob->use(0, *me);
	copiedBob->use(1, *me);
	std::cout << "--------------------" << std::endl << std::endl;

	std::cout << "--------------------" << std::endl;
	std::cout << "Playing with copiedBob" << std::endl;
	std::cout << "--------------------" << std::endl;
	copiedBob->equip(src->createMateria("cure"));
	copiedBob->unequip(0);
	copiedBob->use(0, *me);
	copiedBob->use(1, *me);
	std::cout << "--------------------" << std::endl;

	delete copiedBob;
	delete bob;
	delete me;
	delete src;
	
	return 0;
}
