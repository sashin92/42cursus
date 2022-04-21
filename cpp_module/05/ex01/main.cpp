/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 22:25:14 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 22:25:14 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "--------test1--------" << std::endl;

	Bureaucrat human1("King", 1);
	Bureaucrat human2("Farmer", 60);

	Form f1("Unique form", 20, 20);
	std::cout << f1 << std::endl;
	human1.signForm(f1);
	human2.signForm(f1);

	std::cout << "--------test2--------" << std::endl;
	Form f2("Normal form", 80, 60);
	std::cout << f2 << std::endl;
		human1.signForm(f2);
		human2.signForm(f2);

	return 0;
}
