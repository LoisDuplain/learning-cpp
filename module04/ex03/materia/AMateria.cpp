#include "AMateria.hpp"

AMateria::AMateria(): _type("Unknown")
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
	std::cout << "AMateria used on " << target.getName() << std::endl;
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