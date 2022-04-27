/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:21:57 by sashin            #+#    #+#             */
/*   Updated: 2022/04/27 20:32:42 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
private:
	Intern& operator=(const Intern& src); // unused
	Intern(const Intern& src); // unused

public:
	class FormNameException: public std::exception
	{
	public:
		const char* what(void) const throw();
	};

	Form* makeForm(const std::string& formName, const std::string& target);

	Intern();
	~Intern();
};

#endif
