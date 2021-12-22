#pragma once

#include <stdexcept>
#include <iostream>
#include <algorithm>

class ElementNotFoundException : public std::exception
{
	public:
		ElementNotFoundException(){};
		virtual ~ElementNotFoundException() throw(){};
		virtual const char	*what() const throw() { return "Element not found"; };
};

template<typename T>
int		&easyfind(T &container, int toFind)
{
	typename T::iterator	result;

	result = std::find(container.begin(), container.end(), toFind);
	if (result != container.end())
		return *result;
	throw ElementNotFoundException();
}