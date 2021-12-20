/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:58:18 by lwourms           #+#    #+#             */
/*   Updated: 2021/12/20 14:54:47 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	tryUpGrade(Bureaucrat bc, int grade)
{
	std::cout << "Begin: " << bc << std::endl;
	std::cout << "Trying to upGrade(" << grade << ")" << std::endl;
	try
	{
		bc.upGrade(grade);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "End: " << bc << std::endl << std::endl;
}

void	tryDownGrade(Bureaucrat bc, int grade)
{
	std::cout << "Begin: " << bc << std::endl;
	std::cout << "Trying to downGrade(" << grade << ")" << std::endl;
	try {
		bc.downGrade(grade);
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "End: " << bc << std::endl << std::endl;
}

int main()
{
	Bureaucrat boss("Boss", 10);

	tryUpGrade(boss, 150);
	tryDownGrade(boss, 150);
	tryUpGrade(boss, 50);
	tryDownGrade(boss, 50);

	Bureaucrat	random;
	std::cout << random << std::endl;
	return 0;
}
