/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:02:35 by sashin            #+#    #+#             */
/*   Updated: 2022/01/18 15:02:35 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
: m_weapon(NULL), m_name(name)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
	std::cout << this->m_name << " attacks with his " << this->m_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->m_weapon = &weapon;
}