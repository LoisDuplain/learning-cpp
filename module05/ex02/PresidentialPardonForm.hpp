#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		int static const	_signGrade;
		int static const	_execGrade;
		std::string			_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &src);
		PresidentialPardonForm(std::string target);
		virtual	~PresidentialPardonForm();

		PresidentialPardonForm	&operator=(PresidentialPardonForm const &src);

		void	execute(Bureaucrat const &executor) const;
};
