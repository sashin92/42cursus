/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:34:52 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 13:34:52 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void ScavTrap::attack(const std::string &target)
{
	if (!this->m_hitPoint)
		std::cout << "ScavTrap '" << this->getName() << "' cannot attacks. (HP: 0)" << std::endl;
	else if (!this->m_energyPoint)
		std::cout << "ScavTrap '" << this->getName() << "' cannot attacks. (EP: 0)" << std::endl;
	else
	{
		--(this->m_energyPoint);
		std::cout << "ScavTrap '" << this->getName() << "' attacks " << target << ", causing "
		<< this->getAttackDamage() << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate(void) const
{
	std::cout << "'" << this->getName() << "' is now in 'GATE KEEPER MODE'." << std::endl;
}


ScavTrap::ScavTrap()
: ClapTrap(S_DEFAULT_NAME)
{
	this->m_hitPoint = S_DEFAULT_HP;
	this->m_energyPoint = S_DEFAULT_EP;
	this->m_attackDamage = S_DEFAULT_AD;
	std::cout << "[" << this->getName() << "] ScavTrap is created(default)." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
: ClapTrap(name)
{
	this->m_hitPoint = S_DEFAULT_HP;
	this->m_energyPoint = S_DEFAULT_EP;
	this->m_attackDamage = S_DEFAULT_AD;
	std::cout << "[" << this->getName() << "] ScavTrap is created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)
: ClapTrap(scavTrap.getName())
{
	std::cout << "[" << this->getName() <<  "] ScavTrap is copied(shallow)." << std::endl;
	*this = scavTrap;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
	std::cout << "[" << this->getName() << "] ScavTrap is copied(deep)." << std::endl;
	if (this != &scavTrap)
	{
		this->m_name = scavTrap.getName();
		this->m_hitPoint = scavTrap.getHitPoint();
		this->m_energyPoint = scavTrap.getEnergyPoint();
		this->m_attackDamage = scavTrap.getAttackDamage();
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[" << this->getName() << "] ScavTrap is destroyed." << std::endl;
}
