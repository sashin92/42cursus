/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:30:30 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 10:30:30 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::string s1 = "CT-1";
	std::string s2 = "CT-2";

	ClapTrap c1(s1);
	ClapTrap c2(s2);

	std::cout << std::endl;
	c1.attack(s2);
	c1.attack(s2);
	c1.attack(s2);
	c1.attack(s2);
	c1.attack(s2);
	c1.attack(s2);
	c1.attack(s2);
	c1.attack(s2);
	c1.attack(s2);
	c1.attack(s2);
	c1.attack(s2);
	c1.attack(s2);
	c1.takeDamage(12);
	c1.takeDamage(8);
	c1.beRepaired(6);

	std::cout << std::endl;
	c2.attack(s1);
	c2.takeDamage(5);
	c2.beRepaired(28);

	std::cout << std::endl;
	c1.print();
	c2.print();

	return 0;
}
