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

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "my name is [" << this->m_name << "], claptrap's name is [" << ClapTrap::m_name << "]" << std::endl;
}

std::string DiamondTrap::getName(void) const
{
	return this->m_name;
}

DiamondTrap::DiamondTrap()
: ClapTrap(std::string(C_DEFAULT_NAME) + "_clap_name")
{
	this->m_name = D_DEFAULT_NAME;
	this->m_hitPoint = F_DEFAULT_HP;
	this->m_energyPoint = S_DEFAULT_EP;
	this->m_attackDamage = F_DEFAULT_AD;
	std::cout << "[" << this->getName() << "] FragTrap is created(default)." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
: ClapTrap(name + "_clap_name")
{
	this->m_name = name;
	this->m_hitPoint = F_DEFAULT_HP;
	this->m_energyPoint = S_DEFAULT_EP;
	this->m_attackDamage = F_DEFAULT_AD;
	std::cout << "[" << this->getName() << "] DiamondTrap is created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap)
{
	std::cout << "[" << this->getName() <<  "] FragTrap is copied(shallow)." << std::endl;
	*this = diamondTrap;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
	std::cout << "[" << this->getName() << "] DiamondTrap is copied(deep)." << std::endl;
	if (this != &diamondTrap)
	{
		this->m_name = diamondTrap.getName();
		this->m_hitPoint = diamondTrap.getHitPoint();
		this->m_energyPoint = diamondTrap.getEnergyPoint();
		this->m_attackDamage = diamondTrap.getAttackDamage();
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[" << this->getName() << "] DiamondTrap is destroyed." << std::endl;
}
