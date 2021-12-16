/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:58:20 by lwourms           #+#    #+#             */
/*   Updated: 2021/12/16 12:25:59 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

unsigned int const	Bureaucrat::maxGrade = 1;
unsigned int const	Bureaucrat::minGrade = 150;

Bureaucrat::Bureaucrat(): _name("Default"), _grade(minGrade)
{
}
Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name), _grade(grade)
{
	if (_grade < (int)maxGrade)
		throw GradeTooHighException();
	if (_grade > (int)minGrade)
		throw GradeTooLowException();
}
Bureaucrat::Bureaucrat(Bureaucrat const &src): _name(src._name), _grade(src._grade)
{
	*this = src;
}
Bureaucrat::~Bureaucrat()
{
}

std::string const	Bureaucrat::getName() const
{
	return _name;
}
int const	&Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::upGrade(int const grade)
{
	if (_grade - grade < (int)maxGrade)
		throw GradeTooHighException();
	_grade -= grade;
}

void	Bureaucrat::downGrade(int const grade)
{
	if (_grade + grade > (int)minGrade)
		throw GradeTooLowException();
	_grade += grade;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &src)
{
	_grade = src._grade;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &src)
{
	o << "<" << src.getName() << ">, bureaucrat grade <" << src.getGrade() << ">";
	return o;
}
