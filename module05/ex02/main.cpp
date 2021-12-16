/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:58:18 by lwourms           #+#    #+#             */
/*   Updated: 2021/12/16 14:24:18 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	tryUpGrade(Bureaucrat bc, int grade)
{
	std::cout << "begin: " << bc << std::endl;
	std::cout << "try upGrade(" << grade << ");" << std::endl;
	try {
		bc.upGrade(grade);
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "end: " << bc << std::endl;
}
void	tryDownGrade(Bureaucrat bc, int grade)
{
	std::cout << "begin: " << bc << std::endl;
	std::cout << "try downGrade(" << grade << ");" << std::endl;
	try {
		bc.downGrade(grade);
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "end: " << bc << std::endl;
	std::cout << std::endl;
}

int main()
{
	try {
		Bureaucrat	boss("Boss", 10);
		Bureaucrat	random;

		AForm *form = new ShrubberyCreationForm("coco");
		boss.executeForm(*form);
		boss.signForm(*form);
		boss.executeForm(*form);
		std::cout << std::endl;
		delete form;

		form = new RobotomyRequestForm("top");
		boss.executeForm(*form);
		boss.signForm(*form);
		boss.executeForm(*form);
		std::cout << std::endl;
		delete form;

		form = new PresidentialPardonForm("zou");
		boss.executeForm(*form);
		boss.signForm(*form);
		boss.executeForm(*form);
		std::cout << "Downgrading " << boss << " by 50" << std::endl;
		boss.downGrade(50);
		std::cout << boss << std::endl;
		boss.executeForm(*form);
		delete form;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	catch (AForm::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	return 0;
}
