#pragma once

#include <iostream>

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact		contacts[8];
	int 		number_of_contacts;

	void		display_contact_infos(std::string info);
public:
	PhoneBook();

	void		add_contact();
	void		search();
	void		display();

	Contact*	get_contacts();
	int			get_number_of_contacts();
};
