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

int main(void)
{
	std::string s1 = "Scav-BOT";
	std::string s2 = "Clap-BOT";

	ScavTrap st1(s1);
	ClapTrap ct2(s2);

	std::cout << std::endl;
	ct2.attack("s1");

	std::cout << std::endl;
	st1.guardGate();
	st1.attack(s2);
	ct2.takeDamage(st1.getAttackDamage());
	
	std::cout << std::endl;
	st1.attack(s2);
	ct2.takeDamage(st1.getAttackDamage());


	std::cout << std::endl;
	st1.print();
	ct2.print();

	return 0;
}
