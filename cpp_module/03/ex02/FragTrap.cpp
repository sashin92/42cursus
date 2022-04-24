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

void FragTrap::highFivesGuys(void)
{
	std::cout << this->getName() << " is requesting 'POSITIVE HIGH FIVES'." << std::endl;
}

FragTrap::FragTrap()
{
	this->m_hitPoint = F_DEFAULT_HP;
	this->m_energyPoint = F_DEFAULT_EP;
	this->m_attackDamage = F_DEFAULT_AD;
	std::cout << this->m_name << " FragTrap is created(default)." << std::endl;
}

FragTrap::FragTrap(const std::string &name)
{
	this->m_name = name;
	this->m_hitPoint = F_DEFAULT_HP;
	this->m_energyPoint = F_DEFAULT_EP;
	this->m_attackDamage = F_DEFAULT_AD;
	std::cout << this->m_name << " FragTrap is created." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
	std::cout << this->m_name << " FragTrap is copied(copy assignment overload)." << std::endl;
	if (this != &fragTrap)
	{
		this->m_name = fragTrap.m_name;
		this->m_hitPoint = fragTrap.m_hitPoint;
		this->m_energyPoint = fragTrap.m_energyPoint;
		this->m_attackDamage = fragTrap.m_attackDamage;
	}
	return *this;
}

FragTrap::FragTrap(const FragTrap &fragTrap)
: ClapTrap()
{
	std::cout << this->m_name << " FragTrap is copied(copy constructor)." << std::endl;
	*this = fragTrap;
}

FragTrap::~FragTrap()
{
	std::cout << this->m_name << " FragTrap is destroyed." << std::endl;
}
