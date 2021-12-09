#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
}
Cure::Cure(Cure const &src): AMateria(src._type)
{
	*this = src;
}
Cure::~Cure()
{
}

AMateria	*Cure::clone() const
{
	return new Cure();
}
void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << " wounds *\n";
}

Cure	&Cure::operator=(Cure const &src)
{
	_type = src._type;
	return (*this);
}
