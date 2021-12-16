/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:59:09 by lwourms           #+#    #+#             */
/*   Updated: 2021/12/16 14:42:33 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

int const	ShrubberyCreationForm::_signGrade = 145;
int const	ShrubberyCreationForm::_execGrade = 137;

ShrubberyCreationForm::ShrubberyCreationForm():
AForm("ShrubberyCreationForm", false, _signGrade, _execGrade), _fileName("_shrubbery")
{
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src):
AForm(src), _fileName(src._fileName)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
AForm("ShrubberyCreationForm", false, _signGrade, _execGrade), _fileName(target + "_shrubbery")
{
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream	out;

	AForm::execute(executor);
	std::cout << executor.getName() << " executes " << AForm::getName() << std::endl;
	out.open(_fileName);
	if (_write.fail())
		std::cerr << "Error occured openning the file " << _fileName << std::endl;
	out << "           ._, |_  .,\n"
	"           `-._\\/  .  \\ /    |/_\n"
	"               \\  _\\, y | \\//\n"
	"         _\\_.___\\\\, \\/ -.\\||\n"
	"           `7-,--.`._||  / / ,\n"
	"           /'     `-. `./ / |/_.'\n"
	"                     |    |//\n"
	"                     |_    /\n"
	"                     |-   |\n"
	"                     |   =|\n"
	"                     |    |\n"
	"--------------------/ ,  . \\--------._      "
	<< std::endl;
	out.close();
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	_fileName = src._fileName;
	return *this;
}
