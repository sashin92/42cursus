/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:31:41 by sashin            #+#    #+#             */
/*   Updated: 2022/04/23 17:35:39 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string &target)
{
	if (!this->m_hitPoint)
		std::cout << "ClapTrap " << this->getName() << " cannot attacks. (HP: 0)" << std::endl;
	else if (!this->m_energyPoint)
		std::cout << "ClapTrap " << this->getName() << " cannot attacks. (EP: 0)" << std::endl;
	else
	{
		--(this->m_energyPoint);
		std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << C_DEFAULT_AD << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->m_hitPoint)
	{
		std::cout << "ClapTrap " << this->getName() << " already dead." << std::endl;
		return ;
	}
	if (this->m_hitPoint <= amount)
		this->m_hitPoint = 0;
	else
		this->m_hitPoint -= amount;
	std::cout << "ClapTrap " << this->getName() << " damaged " << amount << " points!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->m_hitPoint)
	{
		std::cout << "ClapTrap " << this->getName() << " already dead." << std::endl;
		return ;
	}
	if (this->m_hitPoint + amount > C_DEFAULT_HP)
	{
		std::cout << "ClapTrap " << this->getName() << " repaired " << (C_DEFAULT_HP - this->m_hitPoint) << " points!" << std::endl;
		this->m_hitPoint = C_DEFAULT_HP;
	}
	else
	{
		this->m_hitPoint += amount;
		std::cout << "ClapTrap " << this->getName() << " repaired " << amount << " points!" << std::endl;
	}
}

std::string ClapTrap::getName(void) const
{
	return this->m_name;
}

int ClapTrap::getHitPoint(void) const
{
	return this->m_hitPoint;
}

int ClapTrap::getEnergyPoint(void) const
{
	return this->m_energyPoint;
}

int ClapTrap::getAttackDamage(void) const
{
	return this->m_attackDamage;
}

void ClapTrap::setName(std::string name)
{
	this->m_name = name;
}

void ClapTrap::setHitPoint(unsigned int hp)
{
	this->m_hitPoint = hp;
}

void ClapTrap::setEnergyPoint(unsigned int ep)
{
	this->m_energyPoint = ep;
}

void ClapTrap::setAttackDamage(unsigned int ad)
{
	this->m_attackDamage = ad;
}

ClapTrap::ClapTrap()
: m_name(C_DEFAULT_NAME), m_hitPoint(C_DEFAULT_HP), m_energyPoint(C_DEFAULT_EP), m_attackDamage(C_DEFAULT_AD)
{
	std::cout << "[" << this->getName() << "] ScavTrap is created(default)." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
: m_name(name), m_hitPoint(C_DEFAULT_HP), m_energyPoint(C_DEFAULT_EP), m_attackDamage(C_DEFAULT_AD)
{
	std::cout << "[" << this->getName() << "] ClapTrap is created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	std::cout << "[" << this->getName() <<  "] ClapTrap is copied(shallow)." << std::endl;
	*this = clapTrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
	std::cout << "[" << this->getName() << "] ClapTrap is copied(deep)." << std::endl;
	if (this != &clapTrap)
	{
		this->m_name = clapTrap.getName();
		this->m_hitPoint = clapTrap.getHitPoint();
		this->m_energyPoint = clapTrap.getEnergyPoint();
		this->m_attackDamage = clapTrap.getAttackDamage();
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[" << this->getName() << "] ClapTrap is destroyed." << std::endl;
}


std::ostream& operator<<(std::ostream& os, const ClapTrap& c)
{
	return os
	<< "Name: " << c.getName()
	<< "\nHitPoint: " << c.getHitPoint()
	<< "\nEnergyPoint: " << c.getEnergyPoint()
	<< "\nAttackDamage: " << c.getAttackDamage();
}
