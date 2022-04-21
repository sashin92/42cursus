/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:31:41 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 10:31:41 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void ClapTrap::print(void) const
{
	std::cout
	<< "Name: " << this->getName() << std::endl
	<< "HitPoint: " << this->getHitPoint() << std::endl
	<< "EnergyPoint: " << this->getEnergyPoint() << std::endl
	<< "AttackDamage: " << this->getAttackDamage() <<std::endl
	<< std::endl;
}

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
	this->m_hitPoint += amount;
	std::cout << "ClapTrap " << this->getName() << " repaired " << amount << " points!" << std::endl;
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
	std::cout << "name '" << this->getName() << "' is created(default)." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
: m_name(name), m_hitPoint(C_DEFAULT_HP), m_energyPoint(C_DEFAULT_EP), m_attackDamage(C_DEFAULT_AD)
{
	std::cout << "name '" << this->getName() << "' is created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	std::cout << "name '" << this->getName() << "' is copied(shallow)." << std::endl;
	*this = clapTrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
	std::cout << "name '" << this->getName() << "' is copied(deep)." << std::endl;
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
	std::cout << "name '" << this->getName() << "' is destroyed." << std::endl;
}
