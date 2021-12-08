#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain created" << std::endl;
}
Brain::Brain(Brain const &src)
{
	*this = src;
	std::cout << "Brain copied" << std::endl;
}
Brain::~Brain()
{
	std::cout << "Brain destroyed" << std::endl;
}

const std::string	*Brain::getIdeas() const
{
	return _ideas;
}
void				Brain::setIdeas(const std::string ideas[100])
{
	for (size_t i = 0; i < 100; i++)
		_ideas[i] = ideas[i];
}

Brain	&Brain::operator=(Brain const &src)
{
	for (size_t i = 0; i < 100; i++)
		_ideas[i] = src._ideas[i];
	return *this;
}