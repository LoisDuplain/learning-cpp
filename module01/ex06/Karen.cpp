#include "Karen.hpp"

Karen::Karen(void)
{
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
}
Karen::~Karen(void)
{
}

void Karen::debug(void)
{
	std::cout << "I love to get extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. ";
	std::cout << "I just love it!" << std::endl;
}
void Karen::info(void)
{
	std::cout <<"I cannot believe adding extra bacon cost more money. ";
	std::cout << "You don’t put enough! If you did I would not have to ask for it!";
	std::cout << std::endl;
}
void Karen::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming here for years and you just started working here last month.";
	std::cout << std::endl;
}
void Karen::error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now.";
	std::cout << std::endl;
}

void Karen::complain(std::string level)
{
	int	log_level;

	if (level == levels[0])
		log_level = 0;
	else if (level == levels[1])
		log_level = 1;
	else if (level == levels[2])
		log_level = 2;
	else if (level == levels[3])
		log_level = 3;
	else
		log_level = -1;
	
	if (log_level != -1)
		std::cout << "[ " << level << " ]" << std::endl;

	switch (log_level)
	{
	case 0:
		debug();
		break;
	case 1:
		info();
		break;
	case 2:
		warning();
		break;
	case 3:
		error();
		break;
	
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}