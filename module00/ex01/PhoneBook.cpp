#include "PhoneBook.hpp"
#include "Utils.hpp"

PhoneBook::PhoneBook() : number_of_contacts(0)
{
}

void		PhoneBook::add_contact()
{
	if (number_of_contacts == 8)
	{
		std::cout << "Your phonebook is full" << std::endl;
		return;
	}
	
	Contact* contact = &contacts[number_of_contacts];

	contact->set_first_name(ask_field("First name", true, false));
	contact->set_last_name(ask_field("Last name", true, false));
	contact->set_nickname(ask_field("Nickname", true, true));
	contact->set_phone_number(ask_field("Phone number", false, true, 10));
	contact->set_darkest_secret(ask_field("Darkest secret", true, true));
	
	number_of_contacts++;
}

void		PhoneBook::search()
{
	if (number_of_contacts <= 0)
	{
		std::cout << "You don't have any contact in your phonebook" << std::endl;
		return;
	}
	display();

	while (true)
	{
		int contact_index;
		
		do {
			std::string line = ask_field("Contact index", false, true); 
			if (line == "None" || line == "EXIT")
				return;
			
			contact_index = std::atoi(line.c_str());
			if (contact_index < 0 || contact_index >= number_of_contacts)
			{
				std::cout << "Wrong contact index" << std::endl;
				continue;
			}
			contacts[contact_index].display();
		} while (contact_index < 0 || contact_index > number_of_contacts - 1);
	}
}

void		PhoneBook::display_contact_infos(std::string info)
{
	std::cout << " " << std::setw(10);
	if (info.size() > 10)
		std::cout << info.substr(0, 9).append(".");
	else
		std::cout << info;
	std::cout << " |";
}

void		PhoneBook::display()
{
	std::cout << "|---------------------------------------------------|" << std::endl;
	std::cout << "|      Index | First Name |  Last Name |   Nickname |" << std::endl;
	std::cout << "|---------------------------------------------------|" << std::endl;
	for (int i = 0; i < this->number_of_contacts; i++)
	{
		Contact contact = contacts[i];

		std::cout << "|";

		std::cout << " " << std::setw(10);
		std::cout << i << " |";

		display_contact_infos(contact.get_first_name());
		display_contact_infos(contact.get_last_name());
		display_contact_infos(contact.get_nickname());
		
		std::cout << std::endl;
	}
	std::cout << "|---------------------------------------------------|" << std::endl;
}

Contact*	PhoneBook::get_contacts()
{
	return this->contacts;
}
int			PhoneBook::get_number_of_contacts()
{
	return this->number_of_contacts;
}
