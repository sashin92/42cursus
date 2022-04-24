/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:57:49 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 15:57:49 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void DiamondTrap::whoAmI()
{
	std::cout << "my name is " << this->m_name << ", claptrap's name is " << ClapTrap::m_name << "." << std::endl;
}

std::string DiamondTrap::getName(void) const
{
	return this->m_name;
}

DiamondTrap::DiamondTrap()
: ClapTrap(std::string(DEFAULT_NAME) + "_clap_name")
{
	this->m_name = DEFAULT_NAME;
	this->m_hitPoint = F_DEFAULT_HP;
	this->m_energyPoint = S_DEFAULT_EP;
	this->m_attackDamage = F_DEFAULT_AD;
	std::cout << this->m_name << " FragTrap is created(default)." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
: ClapTrap(name + "_clap_name")
{
	this->m_name = name;
	this->m_hitPoint = F_DEFAULT_HP;
	this->m_energyPoint = S_DEFAULT_EP;
	this->m_attackDamage = F_DEFAULT_AD;
	std::cout << this->m_name << " DiamondTrap is created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap)
{
	std::cout << this->m_name << " FragTrap is copied(copy assignment overload)." << std::endl;
	*this = diamondTrap;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
	std::cout << this->m_name << " DiamondTrap is copied(copy constructor)." << std::endl;
	if (this != &diamondTrap)
	{
		this->m_name = diamondTrap.m_name;
		this->m_hitPoint = diamondTrap.m_hitPoint;
		this->m_energyPoint = diamondTrap.m_energyPoint;
		this->m_attackDamage = diamondTrap.m_attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << this->m_name << " DiamondTrap is destroyed." << std::endl;
}
