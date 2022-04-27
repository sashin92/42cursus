/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 22:25:14 by sashin            #+#    #+#             */
/*   Updated: 2022/04/27 13:29:20 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "--------test1--------" << std::endl;
	try
	{
		Bureaucrat human("King", 1);
		std::cout << "current: "<< human << std::endl;
		std::cout << human << std::endl;
		human.incrementGrade();
		std::cout << "after incrementGrade: "<< human << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "[error] " << e.what() << std::endl;
	}

	std::cout << "--------test2--------" << std::endl;
	try
	{
		Bureaucrat human("Slave", 150);
		std::cout << "current: "<< human << std::endl;
		std::cout << human << std::endl;
		human.decrementGrade();
		std::cout << "after decrementGrade: "<< human << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "[error] " << e.what() << std::endl;
	}

	std::cout << "--------test3--------" << std::endl;
	try
	{
		Bureaucrat human("sashin", 34);
		std::cout << "current: "<< human << std::endl;
		human.decrementGrade();
		std::cout << "after decrementGrade: "<< human << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "[error] " << e.what() << std::endl;
	}

	return 0;
}
