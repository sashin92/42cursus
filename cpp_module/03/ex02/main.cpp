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
	std::string s1 = "Scav-BOT";
	std::string s2 = "Clap-BOT";
	std::string s3 = "Frag-BOT";

	ScavTrap st1(s1);
	ClapTrap ct2(s2);
	FragTrap ft3(s3);

	std::cout << std::endl;
	ft3.highFivesGuys();
	ct2.attack(s1);

	std::cout << std::endl;
	st1.guardGate();

	std::cout << std::endl;
	st1.attack(s2);
	ct2.takeDamage(st1.getAttackDamage());
	st1.attack(s3);
	ft3.takeDamage(st1.getAttackDamage());

	std::cout << std::endl;
	ft3.attack(s1);
	st1.takeDamage(ft3.getAttackDamage());
	ft3.beRepaired(42);

	std::cout << std::endl;
	st1.print();
	ct2.print();
	ft3.print();

	return 0;
}
