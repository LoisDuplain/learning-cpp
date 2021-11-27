#include <iostream>

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;

	/*
	DEBUG

	RESET NUMBER OF CONTACT (NOT 1 BUT 0)
	*/

	phonebook.get_contacts()[0].set_first_name("Lois");
	phonebook.get_contacts()[0].set_last_name("Duplain");
	phonebook.get_contacts()[0].set_nickname("lololegrosplot");
	phonebook.get_contacts()[0].set_phone_number("0768824773");
	phonebook.get_contacts()[0].set_darkest_secret("Je vois encore mon ex");

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