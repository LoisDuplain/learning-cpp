/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:58:23 by lwourms           #+#    #+#             */
/*   Updated: 2021/12/16 12:26:28 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		unsigned int static const	maxGrade;
		unsigned int static const	minGrade;

		Bureaucrat();
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &src);
		virtual	~Bureaucrat();

		std::string const	getName() const;
		int const			&getGrade() const;

		void	upGrade(int const grade);
		void	downGrade(int const grade);

		Bureaucrat		&operator=(Bureaucrat const &src);

		class GradeTooHighException: public std::exception {
			public:
				virtual const char	*what() const throw() {
					return "Grade is too high for a bureaucrat";
				}
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char	*what() const throw() {
					return "Grade is too low for a bureaucrat";
				}
		};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &src);
