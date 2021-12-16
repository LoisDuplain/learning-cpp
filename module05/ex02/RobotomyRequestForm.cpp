/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:59:09 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/27 17:10:11 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

int const	RobotomyRequestForm::_signGrade = 72;
int const	RobotomyRequestForm::_execGrade = 45;

RobotomyRequestForm::RobotomyRequestForm():
AForm("RobotomyRequestForm", false, _signGrade, _execGrade), _target("Default")
{
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src):
AForm(src), _target(src._target)
{
}
RobotomyRequestForm::RobotomyRequestForm(std::string target):
AForm("RobotomyRequestForm", false, _signGrade, _execGrade), _target(target)
{
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	srand(time(NULL));
	int randomNb = rand() % 2;
	std::cout << executor.getName() << " try to executes " << AForm::getName() << std::endl;
	std::cout << "Bzzzz bzzzz " << std::endl;
	if (randomNb)
		std::cout << executor.getName() << " has robotomized <" << _target << "> " << std::endl;
	else
		std::cout << "<" << _target << "> robotomization has failed" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	_target = src._target;
	return *this;
}
