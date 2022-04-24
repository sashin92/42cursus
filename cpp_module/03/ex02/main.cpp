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
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::string s1 = "[User1]";
	std::string s2 = "[User2]";

	ScavTrap st1(s1);
	FragTrap ft2(s2);

	std::cout << std::endl;
	ft2.highFivesGuys();
	ft2.attack(s1);
	st1.takeDamage(ft2.getAttackDamage());

	std::cout << std::endl;
	st1.guardGate();
	st1.beRepaired(42);

	std::cout << std::endl;
	st1.attack(s2);
	ft2.takeDamage(st1.getAttackDamage());

	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Name: " << st1.getName() << "\n"
	<< st1 << std::endl;

	std::cout << std::endl;
	std::cout << "Name: " << ft2.getName() << "\n"
	<< ft2 << std::endl;
	std::cout << std::endl;


	return 0;
}
