#pragma once

#include <iostream>

class Brain
{
	public:
		std::string	_ideas[100];

		Brain(void);
		Brain(Brain const &src);
		~Brain();

		const std::string	*getIdeas()	const;
		void		setIdeas(const std::string ideas[100]);

		Brain	&operator=(Brain const &src);
};