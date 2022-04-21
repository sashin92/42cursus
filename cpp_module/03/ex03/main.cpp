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
#include "DiamondTrap.hpp"

int main(void)
{
	std::string s = "Diam-BOT";

	DiamondTrap dt(s);

	std::cout << std::endl;
	dt.whoAmI();

	std::cout << std::endl;
	dt.highFivesGuys();

	std::cout << std::endl;
	dt.guardGate();

	std::cout << std::endl;
	dt.takeDamage(24);
	dt.beRepaired(42);
	dt.attack("someone");

	std::cout << std::endl;
	dt.print();

	return 0;
}
