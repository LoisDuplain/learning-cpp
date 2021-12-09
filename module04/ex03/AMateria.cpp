#include "AMateria.hpp"

AMateria::AMateria(): _type("Default")
{
}
AMateria::AMateria(std::string const &type): _type(type)
{
}
AMateria::AMateria(AMateria const &src)
{
	*this = src;
}
AMateria::~AMateria()
{
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* used generic materia on " << target.getName() << " *\n";
}

std::string const	&AMateria::getType() const
{
	return _type;
}

AMateria	&AMateria::operator=(AMateria const &src)
{
	_type = src._type;
	return *this;
}