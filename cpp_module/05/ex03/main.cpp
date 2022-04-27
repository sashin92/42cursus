/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 22:25:14 by sashin            #+#    #+#             */
/*   Updated: 2022/04/27 20:27:51 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Intern someRandomIntern;
	std::cout << "-----test1-------" << std::endl;
	Form* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;

	std::cout << "-----test2-------" << std::endl;
	Form* tmp;
	tmp = someRandomIntern.makeForm("Receipt", "my_market");
	if (tmp)
	{
		std::cout << *tmp << std::endl;
		delete tmp;
	}

	std::cout << "-----------------" << std::endl;
	delete rrf;

	return 0;
}
