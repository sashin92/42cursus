/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:42:56 by sashin            #+#    #+#             */
/*   Updated: 2022/04/27 18:56:27 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::execute(const Bureaucrat& b) const
{
	try
	{
		executableCheck(b);
		std::cout << b.getName() << " executed " << getName() << std::endl;
		std::cout << "* Informs that " << getName()
		<< " has been pardoned by Zaphod Beeblebrox *" << std::endl;
	}
	catch (std::exception &e)
	{
	std::cerr << b.getName() << " couldn't execute " << getName()
		<< " because " << e.what() << std::endl;
	}

}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: Form(target, static_cast<const int>(PP_SIGN_GRADE), static_cast<const int>(PP_EXEC_GRADE))
{
	std::cout << "[PresidentialPardonForm] constructor called." << std::endl;
}

// PresidentialPardonForm::PresidentialPardonForm() {} // unused
// PresidentialPardonForm::PresidentialPardonForm &operator=(const PresidentialPardonForm& src) {} // unused

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
: Form(src)
{
	std::cout << "[PresidentialPardonForm] copy constructor called." << std::endl;
}


PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm] destructor called." << std::endl;
}
