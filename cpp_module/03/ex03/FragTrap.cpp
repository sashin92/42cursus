/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:09:54 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 15:09:54 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void FragTrap::attack(const std::string &target)
{
	if (!this->m_hitPoint)
		std::cout << "FragTrap '" << this->getName() << "' cannot attacks. (HP: 0)" << std::endl;
	else if (!this->m_energyPoint)
		std::cout << "FragTrap '" << this->getName() << "' cannot attacks. (EP: 0)" << std::endl;
	else
	{
		--(this->m_energyPoint);
		std::cout << "FragTrap '" << this->getName() << "' attacks " << target << ", causing "
		<< this->getAttackDamage() << " points of damage!" << std::endl;
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "'" << this->getName() << "' is requesting 'POSITIVE HIGH FIVES'." << std::endl;
}

FragTrap::FragTrap()
: ClapTrap(F_DEFAULT_NAME)
{
	this->m_hitPoint = F_DEFAULT_HP;
	this->m_energyPoint = F_DEFAULT_EP;
	this->m_attackDamage = F_DEFAULT_AD;
	std::cout << "[" << this->getName() << "] FragTrap is created(default)." << std::endl;
}

FragTrap::FragTrap(const std::string &name)
: ClapTrap(name)
{
	this->m_hitPoint = F_DEFAULT_HP;
	this->m_energyPoint = F_DEFAULT_EP;
	this->m_attackDamage = F_DEFAULT_AD;
	std::cout << "[" << this->getName() << "] FragTrap is created." << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap)
: ClapTrap(fragTrap.getName())
{
	std::cout << "[" << this->getName() <<  "] FragTrap is copied(shallow)." << std::endl;
	*this = fragTrap;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
	std::cout << "[" << this->getName() << "] FragTrap is copied(deep)." << std::endl;
	if (this != &fragTrap)
	{
		this->m_name = fragTrap.getName();
		this->m_hitPoint = fragTrap.getHitPoint();
		this->m_energyPoint = fragTrap.getEnergyPoint();
		this->m_attackDamage = fragTrap.getAttackDamage();
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "[" << this->getName() << "] FragTrap is destroyed." << std::endl;
}
