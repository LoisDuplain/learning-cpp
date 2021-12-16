/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:58:23 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/27 17:54:14 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class Intern
{
	private:
		int static const	_formNb;
		AForm static	*createShrubbery(std::string target);
		AForm static	*createRobotomy(std::string target);
		AForm static	*createPresidential(std::string target);

	public:
		Intern();
		Intern(Intern const &src);
		virtual	~Intern();

		AForm	*makeForm(std::string formName, std::string target) const;

		Intern		&operator=(Intern const &src);

		class NotRightFormException: public std::exception {
			private:
				std::string	_msg;
			public:
				NotRightFormException(std::string formName) {
					std::stringstream	s;
					s << "form <" << formName << "> can't be created";
					_msg = s.str();
				}
				virtual const char	*what() const throw() {
					return _msg.c_str();
				}
				virtual	~NotRightFormException() throw() {}
		};
};
