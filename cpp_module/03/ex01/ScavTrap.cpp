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
		std::cout << "ScavTrap " << this->m_name << " cannot attacks. (HP: 0)" << std::endl;
	else if (!this->m_energyPoint)
		std::cout << "ScavTrap " << this->m_name << " cannot attacks. (EP: 0)" << std::endl;
	else
	{
		--(this->m_energyPoint);
		std::cout << "ScavTrap " << this->m_name << " attacks " << target << ", causing " << this->m_attackDamage << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate(void) const
{
	std::cout << this->m_name << " is now in 'GATE KEEPER MODE'." << std::endl;
}

ScavTrap::ScavTrap()
{
	this->m_hitPoint = S_DEFAULT_HP;
	this->m_energyPoint = S_DEFAULT_EP;
	this->m_attackDamage = S_DEFAULT_AD;
	std::cout << this->m_name << " ScavTrap is created(default)." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
{
	this->m_name = name;
	this->m_hitPoint = S_DEFAULT_HP;
	this->m_energyPoint = S_DEFAULT_EP;
	this->m_attackDamage = S_DEFAULT_AD;
	std::cout << this->m_name << " ScavTrap is created." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
	std::cout << this->m_name << " ScavTrap is copied(copy assignment overload)." << std::endl;
	if (this != &scavTrap)
	{
		this->m_name = scavTrap.m_name;
		this->m_hitPoint = scavTrap.m_hitPoint;
		this->m_energyPoint = scavTrap.m_energyPoint;
		this->m_attackDamage = scavTrap.m_attackDamage;
	}
	return *this;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)
: ClapTrap()
{
	std::cout << this->m_name << " ScavTrap is copied(copy constructor)." << std::endl;
	*this = scavTrap;
}

ScavTrap::~ScavTrap()
{
	std::cout << this->m_name << " ScavTrap is destroyed." << std::endl;
}
