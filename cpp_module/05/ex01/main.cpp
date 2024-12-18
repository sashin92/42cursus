/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 22:25:14 by sashin            #+#    #+#             */
/*   Updated: 2022/04/27 20:29:23 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat human1("Programmer", 60);
	Bureaucrat human2("King", 1);

	std::cout << "---------------------" << std::endl;
	std::cout << human1 << std::endl;
	std::cout << human2 << std::endl;
	std::cout << std::endl;

	std::cout << "--------test1--------" << std::endl;
	Form f1("Unique form", 20, 20);
	std::cout << f1 << std::endl;
	human1.signForm(f1);
	std::cout << f1 << std::endl;
	human2.signForm(f1);
	std::cout << f1 << std::endl;
	std::cout << std::endl;

	std::cout << "--------test2--------" << std::endl;
	Form f2("Normal form", 80, 60);
	std::cout << f2 << std::endl;
	human1.signForm(f2);
	std::cout << f2 << std::endl;
	human2.signForm(f2);
	std::cout << f2 << std::endl;
	std::cout << std::endl;

	std::cout << "---------------------" << std::endl;

	return 0;
}
