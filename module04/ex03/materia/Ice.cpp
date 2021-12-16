#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
}
Ice::Ice(Ice const &src): AMateria(src._type)
{
	*this = src;
}
Ice::~Ice()
{
}

AMateria	*Ice::clone() const
{
	return new Ice();
}
void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

Ice	&Ice::operator=(Ice const &src)
{
	_type = src._type;
	return (*this);
}
