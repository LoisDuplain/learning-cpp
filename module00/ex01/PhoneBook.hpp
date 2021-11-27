#pragma once

#include <iostream>

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact		contacts[8];
	int 		number_of_contact;

	void		display_contact_info(std::string info);
public:
	PhoneBook();

	void		add_contact();
	void		search();
	void		display();

	Contact*	get_contacts();
	int			get_number_of_contact();
};
