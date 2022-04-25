/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:41:21 by sashin            #+#    #+#             */
/*   Updated: 2022/04/25 12:05:21 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


const AMateria* Character::getMateria(int idx) const
{
	return m_materiaInventory[idx];
}

const std::string & Character::getName() const
{
	return m_name;
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
			std::cout << "Please valid equip materia." << std::endl;
		return ;
	}
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (!m_materiaInventory[i])
		{
			m_materiaInventory[i] = m;
			std::cout << m_name << " equiped a materia: " << m->getType() << std::endl;
			return ;
		}
	}
	std::cout << m_name << " FAILED to equip a materia. (Full inventory)" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < INVENTORY_SIZE && m_materiaInventory[idx])
	{
		std::cout << m_name << " unequiped a materia: " << m_materiaInventory[idx]->getType() << std::endl;
		m_materiaInventory[idx] = NULL;
	}
	else
		std::cout << m_name << " FAILED to unequip a materia." << std::endl;

}


void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < INVENTORY_SIZE && m_materiaInventory[idx])
	{
		m_materiaInventory[idx]->use(target);
		std::cout << m_name << " used a materia: " << *m_materiaInventory[idx] << std::endl;
	}
	else
		std::cout << m_name << " FAILED to use a materia." << std::endl;
}

Character::Character()
{
	std::cout << "Character constructor called. (default)" <<std::endl;
	m_name = DEFAULT_NAME;
	for (int i = 0; i < INVENTORY_SIZE; ++i)
	{
		m_materiaInventory[i] = NULL;
	}
}

Character::Character(const std::string& name)
{
	std::cout << "Character constructor called. (with name)" <<std::endl;
	m_name = name;
	for (int i = 0; i < INVENTORY_SIZE; ++i)
	{
		m_materiaInventory[i] = NULL;
	}
}

Character::Character(const Character &src)
{
	std::cout << "Character copy constructor called." <<std::endl;
	*this = src;
}

Character &Character::operator=(const Character &src)
{
	std::cout << "Character copy assignment operator called." <<std::endl;
	if (this != &src)
	{
		m_name = src.m_name;
		for (int i = 0; i < INVENTORY_SIZE; i++)
		{
			if (m_materiaInventory[i])
			{
				delete m_materiaInventory[i];
				m_materiaInventory[i] = NULL;
			}
			m_materiaInventory[i] = src.m_materiaInventory[i];
		}
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character destructor called." <<std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (m_materiaInventory[i])
		{
			delete m_materiaInventory[i];
			m_materiaInventory[i] = NULL;
		}
	}
}
