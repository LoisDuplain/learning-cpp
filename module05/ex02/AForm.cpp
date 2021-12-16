/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:58:20 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/26 17:33:18 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

int const	AForm::_maxGrade = 1;
int const	AForm::_minGrade = 150;

AForm::AForm():
_name("Default"), _gradeSign(_minGrade), _gradeExec(_maxGrade), _signed(false)
{
}
AForm::AForm(std::string const &name, int const grade):
_name(name), _gradeSign(grade), _gradeExec(_maxGrade), _signed(false)
{
	if (_gradeSign < _maxGrade)
		throw GradeTooHighException(*this);
	if (_gradeSign > _minGrade)
		throw GradeTooLowException(*this);
}
AForm::AForm(std::string name, bool isSigned, unsigned int gradeSign, unsigned int gradeExec):
_name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(isSigned)
{
	if (_gradeSign > _minGrade || _gradeExec > _minGrade)
		throw GradeTooLowException(*this);
	else if (_gradeSign < _maxGrade || _gradeExec < _maxGrade)
		throw GradeTooHighException(*this);
}
AForm::AForm(AForm const &src):
_name(src._name), _gradeSign(src._gradeSign), _gradeExec(src._maxGrade), _signed(src._signed)
{
	*this = src;
}
AForm::~AForm()
{
}

std::string	AForm::getName() const
{
	return _name;
}
int const	&AForm::getGrade() const
{
	return _gradeSign;
}
int const	&AForm::getGradeExec() const
{
	return _gradeExec;
}
bool	&AForm::getSigned()
{
	return _signed;
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw GradeTooLowException(*this, bureaucrat);
	else
		_signed = true;
}
void	AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > _gradeExec || _signed == false)
		throw IllegalFormExecutionException(*this, executor, _signed);
}

AForm	&AForm::operator=(AForm const &src)
{
	_signed = src._signed;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, AForm const &src)
{
	o
	<< "<"
	<< src.getName()
	<< "> of signed grade <"
	<< src.getGrade()
	<< "> and execution grade <"
	<< src.getGradeExec()
	<< ">";
	
	return o;
}
