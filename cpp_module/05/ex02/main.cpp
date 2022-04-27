/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 22:25:14 by sashin            #+#    #+#             */
/*   Updated: 2022/04/27 20:28:43 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat human1("KING", 1);
	Bureaucrat human2("SLAVE", 149);
	Bureaucrat human3("SASHIN", 40);

	ShrubberyCreationForm sf("Plant");
	RobotomyRequestForm rr("Robot");
	PresidentialPardonForm pp("Kirby");
	
	std::cout << "---------------------" << std::endl;
	std::cout << "--------test1--------" << std::endl;
	std::cout << "---------------------" << std::endl;
	sf.execute(human1);
	rr.execute(human1);
	pp.execute(human1);
	std::cout << "---------------------" << std::endl;
	std::cout << "--------test2--------" << std::endl;
	std::cout << "---------------------" << std::endl;
	sf.execute(human2);
	rr.execute(human2);
	pp.execute(human2);
	std::cout << "---------------------" << std::endl;
	std::cout << "--------test3--------" << std::endl;
	std::cout << "---------------------" << std::endl;
	sf.execute(human3);
	rr.execute(human3);
	pp.execute(human3);
	std::cout << "---------------------" << std::endl;

	return 0;
}
