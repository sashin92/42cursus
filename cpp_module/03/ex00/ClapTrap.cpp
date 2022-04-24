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
		std::cout << "ClapTrap " << this->m_name << " cannot attacks. (HP: 0)" << std::endl;
	else if (!this->m_energyPoint)
		std::cout << "ClapTrap " << this->m_name << " cannot attacks. (EP: 0)" << std::endl;
	else
	{
		--(this->m_energyPoint);
		std::cout << "ClapTrap " << this->m_name << " attacks " << target << ", causing " << this->m_attackDamage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->m_hitPoint)
		std::cout << this->m_name << " cannot take damege. (HP:0)." << std::endl;
	else if (this->m_hitPoint <= amount)
	{
		std::cout << this->m_name << " damaged " << this->m_hitPoint << " points!" << std::endl;
		this->m_hitPoint = 0;
	}
	else
	{
		std::cout << this->m_name << " damaged " << amount << " points!" << std::endl;
		this->m_hitPoint -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->m_hitPoint)
		std::cout << this->m_name << " cannot repair itself. (HP: 0)" << std::endl;
	else if (!this->m_energyPoint)
		std::cout << this->m_name << " cannot repair itself. (EP: 0)" << std::endl;
	else
	{
		this->m_hitPoint += amount;
		std::cout << this->m_name << " repaired " << amount << " points!" << std::endl;
		--(this->m_energyPoint);
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
: m_name(DEFAULT_NAME), m_hitPoint(C_DEFAULT_HP), m_energyPoint(C_DEFAULT_EP), m_attackDamage(C_DEFAULT_AD)
{
	std::cout << this->m_name << " ClapTrap is created(default)." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
: m_name(name), m_hitPoint(C_DEFAULT_HP), m_energyPoint(C_DEFAULT_EP), m_attackDamage(C_DEFAULT_AD)
{
	std::cout << this->m_name << " ClapTrap is created." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
	std::cout << this->m_name << " ClapTrap is copied(copy assignment overload)." << std::endl;
	if (this != &clapTrap)
	{
		this->m_name = clapTrap.m_name;
		this->m_hitPoint = clapTrap.m_hitPoint;
		this->m_energyPoint = clapTrap.m_energyPoint;
		this->m_attackDamage = clapTrap.m_attackDamage;
	}
	return *this;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	std::cout << this->m_name << " ClapTrap is copied(copy constructor)." << std::endl;
	*this = clapTrap;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->m_name << " ClapTrap is destroyed." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const ClapTrap& c)
{
	return os
	<< "HP: " << c.getHitPoint()
	<< ", EP: " << c.getEnergyPoint()
	<< ", AD: " << c.getAttackDamage();
}
