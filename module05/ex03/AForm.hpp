/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm copy.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:58:23 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/26 18:36:28 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

std::ostream	&operator<<(std::ostream &o, AForm const &src);
class AForm
{
	private:
		int static const	_maxGrade;
		int static const	_minGrade;
		std::string const	_name;
		int			const	_gradeSign;
		int			const	_gradeExec;
		bool				_signed;

	public:
		AForm();
		AForm(std::string const &name, int grade);
		AForm(std::string name, bool isSigned, unsigned int gradeSign, unsigned int gradeExec);
		AForm(AForm const &src);
		virtual	~AForm();

		std::string	getName() const;
		int const	&getGrade() const;
		int const	&getGradeExec() const;
		bool		&getSigned();

		void			beSigned(Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const;

		AForm	&operator=(AForm const &src);

		class GradeTooHighException: public std::exception {
			private:
				std::string	_msg;
			public:
				GradeTooHighException(AForm const &f) {
					std::stringstream s;
					s << "grade is too high for " << f;
					_msg = s.str();
				}
				virtual const char	*what() const throw() {
					return _msg.c_str();
				}
				virtual	~GradeTooHighException() throw() {}
		};
		class GradeTooLowException: public std::exception {
			private:
				std::string	_msg;
			public:
				GradeTooLowException(AForm const &f) {
					std::stringstream s;
					s << "grade is too low for " << f;
					_msg = s.str();
				}
				GradeTooLowException(AForm const &f, Bureaucrat const &b) {
					std::stringstream s;
					s << b << " is too low for " << f;
					_msg = s.str();
				}
				virtual const char	*what() const throw() {
					return _msg.c_str();
				}
				virtual ~GradeTooLowException() throw() {};
		};
		class IllegalFormExecutionException: public std::exception {
			private:
				std::string	_msg;
			public:
				IllegalFormExecutionException(AForm const &f, Bureaucrat const &b, bool isSigned) {
					std::stringstream s;
					if (isSigned)
						s << f << " can't be executed by " << b;
					else
						s << f << " is not signed";
					_msg = s.str();
				}
				virtual const char	*what() const throw() {
					return _msg.c_str();
				}
				virtual ~IllegalFormExecutionException() throw() {};
		};
};
