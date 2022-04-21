/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:32:25 by sashin            #+#    #+#             */
/*   Updated: 2022/01/18 11:32:25 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main(void)
{
	Point a(0.0, 0.0);
	Point b(3.0, 0.0);
	Point c(0.0, 4.0);
	Point p1(-1.0, 3.0);
	Point p2(1.0, 0.1);

	std::cout << "a" << a << " b" << b << " c" << c << std::endl;
	std::cout << "p1" << p1 << std::endl;
	if (bsp(a, b, c, p1))
		std::cout << "in!" << std::endl;
	else
		std::cout << "out!" << std::endl;

	std::cout << "-------------------------" << std::endl;

		std::cout << "a" << a << " b" << b << " c" << c << std::endl;
	std::cout << "p2" << p2 << std::endl;
	if (bsp(a, b, c, p2))
		std::cout << "in!" << std::endl;
	else
		std::cout << "out!" << std::endl;

	std::cout << "-------------------------" << std::endl;

		std::cout << "a" << a << " b" << b << " c" << c << std::endl;
	std::cout << "a" << a << std::endl;
	if (bsp(a, b, c, a))
		std::cout << "in!" << std::endl;
	else
		std::cout << "out!" << std::endl;

	return 0;
}
