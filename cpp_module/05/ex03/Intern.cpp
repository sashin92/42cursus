/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:21:44 by sashin            #+#    #+#             */
/*   Updated: 2022/04/27 20:26:50 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <exception>


const char* Intern::FormTypeException::what() const throw()
{
	return "Invalid Form Name";
}

Form* Intern::makeForm(const std::string& formName, const std::string& target)
{
	const std::string formList[3] = {"presidential pardon", "robotomy request", "shrubberycreation"};
	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (formList[i] == formName)
			{
				std::cout << "Intern creates " << formList[i] << std::endl;
				switch (i)
				{
					case 0:
						return new PresidentialPardonForm(target);
					case 1:
						return new RobotomyRequestForm(target);
					case 2:
						return new ShrubberyCreationForm(target);
				}
			}
		}
		throw FormTypeException();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return NULL;
}


Intern::Intern()
{
	std::cout << "[Intern] constructor called." << std::endl;
}

// Intern Intern::&operator=(const Intern& src); // unused
// Intern::Intern(const Intern& src); // unused

Intern::~Intern()
{
	std::cout << "[Intern] destructor called." << std::endl;
}
