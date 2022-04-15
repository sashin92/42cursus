/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:02:35 by sashin            #+#    #+#             */
/*   Updated: 2022/01/18 15:02:35 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
: m_weapon(weapon), m_name(name)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	std::cout << this->m_name << " attacks with his " << this->m_weapon.getType() << std::endl;
}