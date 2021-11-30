#include <iostream>

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;

	std::string	line;
	while (true)
	{
		std::cout << "ADD/SEARCH/EXIT > ";
		std::getline(std::cin, line);
		if (line == "EXIT" || std::cin.eof())
			return (0);
		else if (line == "ADD")
			phonebook.add_contact();
		else if (line == "SEARCH")
			phonebook.search();
		else
			std::cout << "Unknown command" << std::endl;
	}
	return (0);
}