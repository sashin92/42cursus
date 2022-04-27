/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:43:43 by sashin            #+#    #+#             */
/*   Updated: 2022/04/27 19:19:27 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <exception>
#include "RobotomyRequestForm.hpp"

void RobotomyRequestForm::execute(const Bureaucrat& b) const
{
	try
	{
		executableCheck(b);
		std::cout << b.getName() << " executed " << getName() << std::endl;
		srand(time(0));
		if (rand() % 2 == 0)
		{
			std::cout << "drrrrrrrriiiiiiiillll~~~~~~~" << std::endl;
		}
		else
		{
			std::cout << "DDDDDDDDDRRRRRRRRRR........" << std::endl;
		}
	}
	catch (std::exception &e)
	{
	std::cerr << b.getName() << " couldn't execute " << getName()
		<< " because " << e.what() << std::endl;
	}

}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: Form(target, static_cast<const int>(RR_SIGN_GRADE), static_cast<const int>(RR_EXEC_GRADE))
{
	std::cout << "[RobotomyRequestForm] constructor called." << std::endl;
}

// RobotomyRequestForm::RobotomyRequestForm() {} // unused
// RobotomyRequestForm::RobotomyRequestForm &operator=(const RobotomyRequestForm& src) {} // unused

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
: Form(src)
{
	std::cout << "[RobotomyRequestForm] copy constructor called." << std::endl;
}


RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm] destructor called." << std::endl;
}
