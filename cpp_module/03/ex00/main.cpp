/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:30:30 by sashin            #+#    #+#             */
/*   Updated: 2022/04/23 17:33:04 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::string s1 = "[User1]";

	ClapTrap c1(s1);
	ClapTrap c2;

	std::cout << std::endl;
	c1.attack("[someone]");
	c1.attack("[someone]");
	c1.attack("[someone]");
	c1.attack("[someone]");
	c1.attack("[someone]");
	c1.attack("[someone]");
	c1.attack("[someone]");
	c1.attack("[someone]");
	c1.attack("[someone]");
	c1.attack("[someone]");
	c1.attack("[someone]");
	c1.beRepaired(6);
	c1.takeDamage(12);
	c1.takeDamage(12);

	std::cout << std::endl;
	c2.attack(s1);
	c2.takeDamage(5);
	c2.beRepaired(6);

	std::cout << std::endl;
	std::cout << "Name: " << c1.getName() << "\n"
	<< c1 << std::endl;

	std::cout << std::endl;
	std::cout << "Name: " << c2.getName() << "\n"
	<< c2 << std::endl;
	std::cout << std::endl;

	return 0;
}
