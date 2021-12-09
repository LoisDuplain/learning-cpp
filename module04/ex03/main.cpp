#include <iostream>

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "Their tests:\n";
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	std::cout << "\nMy tests:\n";
	ICharacter	*sorcerer = new Character("Pug");
	std::cout << "sorcerer name = " << sorcerer->getName() << std::endl;
	ICharacter	*sorcerer2 = new Character("Bad Sorcerer");
	std::cout << std::endl;

	/////////////////////////////////////////////
	IMateriaSource	*materias = new MateriaSource();
	materias->learnMateria(new Ice());
	AMateria *ice2 =  materias->createMateria("ice");
	ice2->use(*sorcerer);
	AMateria *cure2 =  materias->createMateria("cure");
	if (cure2)
		cure2->use(*sorcerer2);
	materias->learnMateria(new Cure());
	cure2 =  materias->createMateria("cure");
	cure2->use(*sorcerer2);
	std::cout << std::endl;

	///// Unequip() produce needing of free the materia unequiped /////
	sorcerer->equip(ice2);
	sorcerer->equip(cure2);
	sorcerer->use(0, *sorcerer2);
	sorcerer->use(1, *sorcerer2);
	sorcerer->unequip(1);
	sorcerer->use(1, *sorcerer2);
	std::cout << std::endl;

	////////// Clone /////////////
	std::cout << "Testing clones" << std::endl;
	AMateria *clone_cure2 =  cure2->clone();
	clone_cure2->use(*sorcerer);
	std::cout << std::endl;

	////////// Deep Copy test /////////////
	std::cout << "Testing deep copy" << std::endl;
	Character tanis("Tanis");
	tanis.equip(clone_cure2);
	ICharacter *coco = new Character(tanis);
	std::cout << "New charecter from deep copy = " << coco->getName() << std::endl;
	coco->use(0, *sorcerer2);

	delete sorcerer;
	delete sorcerer2;
	delete materias;
	delete cure2;
	delete coco;
	return 0;
}
