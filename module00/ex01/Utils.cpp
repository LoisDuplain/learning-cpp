#include "Utils.hpp"

bool	contains_digit(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
        if (isdigit(str[i]))
            return (true);
    return (false);
}

bool	contains_alpha(std::string str)
{
     for (size_t i = 0; i < str.size(); i++)
        if (isalpha(str[i]))
            return (true);
    return (false);
}

bool	is_valid_field_entry(std::string field_entry, bool can_contains_alpha, bool can_contains_digit, size_t size)
{
	if (field_entry == "None")
		return (true);
	if (!can_contains_alpha && contains_alpha(field_entry))
	{
		std::cout << "Entry cannot contains alpha characters" << std::endl;
		return (false);
	}
	if (!can_contains_digit && contains_digit(field_entry))
	{
		std::cout << "Entry cannot contains digit character" << std::endl;
		return (false);
	}
	if (size != 0 && field_entry.size() != size)
	{
		std::cout << "Entry must be " << size << " characters long" << std::endl;
		return (false);
	}
	return (field_entry != "");
}

std::string	ask_field(std::string field_name, bool can_contains_alpha, bool can_contains_digit)
{
	return ask_field(field_name, can_contains_alpha, can_contains_digit, 0);
}

std::string	ask_field(std::string field_name, bool can_contains_alpha, bool can_contains_digit, size_t size)
{
	std::string	field_entry;

	do {
		std::cout << field_name << ": ";
		std::getline(std::cin, field_entry);
		if (std::cin.eof())
		{
			std::cout << "EXIT" << std::endl;
			return ("EXIT");
		}
	} while (!is_valid_field_entry(field_entry, can_contains_alpha, can_contains_digit, size));
	
	return field_entry;
}