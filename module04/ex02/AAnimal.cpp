#include "AAnimal.hpp"

AAnimal::~AAnimal(void)
{
}

std::string	AAnimal::getType(void)	const
{
	return _type;
}

AAnimal	&AAnimal::operator=(AAnimal const &o)
{
	_type = o._type;
	return *this;
}