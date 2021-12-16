/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:58:20 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/26 17:33:18 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int const	Form::maxGrade = 1;
int const	Form::minGrade = 150;

Form::Form()	:	_name("Default"), _gradeSign(minGrade), _gradeExec(minGrade), _signed(false)
{
}
Form::Form(std::string const &name, int const signedGrade, int const execGrade)	:	_name(name), _gradeSign(signedGrade), _gradeExec(execGrade), _signed(false)
{
	if (_gradeSign < maxGrade)
		throw GradeTooHighException(*this);
	if (_gradeSign > minGrade)
		throw GradeTooLowException(*this);
	if (_gradeExec < maxGrade)
		throw GradeTooHighException(*this);
	if (_gradeExec > minGrade)
		throw GradeTooLowException(*this);
}
Form::Form(Form const &src)	:	_name(src._name), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec)
{
	*this = src;
}
Form::~Form()
{
}

std::string	Form::getName() const
{
	return _name;
}
int const	&Form::getSignedGrade() const
{
	return _gradeSign;
}
int const	&Form::getExecGrade() const
{
	return _gradeExec;
}
bool	&Form::getSigned()
{
	return _signed;
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw GradeTooLowException(*this);
	else
		_signed = true;
}

Form	&Form::operator=(Form const &src)
{
	_signed = src._signed;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Form const &src)
{
	o
	<< "<"
	<< src.getName()
	<< "> of signed grade <"
	<< src.getSignedGrade()
	<< "> and of execution grade <"
	<< src.getExecGrade()
	<< ">";
	
	return o;
}
