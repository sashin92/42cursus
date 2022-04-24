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

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap dt("[BOSS]");

	std::cout << std::endl;
	dt.whoAmI();

	std::cout << std::endl;
	dt.highFivesGuys();

	std::cout << std::endl;
	dt.guardGate();

	std::cout << std::endl;
	dt.attack("[someone]");

	std::cout << std::endl;
	std::cout << "Name: " << dt.getName() << "\n"
	<< dt << "\n" << std::endl;

	return 0;
}
