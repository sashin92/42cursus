/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:46:25 by sashin            #+#    #+#             */
/*   Updated: 2022/04/29 19:03:43 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::cout << "------dup check--------" << std::endl;
	try
	{
		Span test = Span(3);

		test.addNumber(1);
		test.addNumber(2);
		test.addNumber(1);
		std::cout << "fine?" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

		std::cout << "------capa check--------" << std::endl;
	try
	{
		Span test = Span(3);

		test.addNumber(1);
		test.addNumber(2);
		test.addNumber(3);
		test.addNumber(4);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
		std::cout << "------one size check--------" << std::endl;
	try
	{
		Span test = Span(3);

		test.addNumber(1);
		std::cout << test.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "------So MANY--------" << std::endl;
	Span test = Span(10000);

	test.spanFiller(10000);
	std::cout << "size: " << test.getInteger().size() << std::endl;
	std::cout << "shortest: " << test.shortestSpan() << std::endl;
	std::cout << "Longest: " << test.longestSpan() << std::endl;

	return 0;
}
