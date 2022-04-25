/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:13:41 by sashin            #+#    #+#             */
/*   Updated: 2022/04/25 11:44:19 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

const AMateria* MateriaSource::getAMateria(int idx) const
{
	return m_materiaSource[idx];
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
	{
		std::cout << "learnMateria Failed(empty parameter)" << std::endl;
		return ;
	}
	for (int i = 0; i < MATERIASOURCE_SIZE; i++)
	{
		if (!m_materiaSource[i])
		{
			m_materiaSource[i] = m;
			std::cout << "learnMateria: " << m->getType() << std::endl;
			return ;
		}
	}
	std::cout << "learnMateria Failed(FULL)." << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < MATERIASOURCE_SIZE; i++)
	{
		if (m_materiaSource[i] && m_materiaSource[i]->getType() == type)
		{
			std::cout << "createMateria: " << type << std::endl;
			return m_materiaSource[i]->clone();
		}
	}
	std::cout << "createMateria Failed(Wrong type): " << type << std::endl;

	return 0;
}

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < MATERIASOURCE_SIZE; ++i)
	{
		m_materiaSource[i] = NULL;
	}
	std::cout << "MateriaSource constructor called. (default)" <<std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src)
{
	std::cout << "MateriaSource copy assignment operator called." <<std::endl;
	if (this != &src)
	{
		for (int i = 0; i < MATERIASOURCE_SIZE; ++i)
		{
			if (m_materiaSource[i])
			{
				delete m_materiaSource[i];
				m_materiaSource[i] = NULL;
			}
			m_materiaSource[i] = src.m_materiaSource[i];
		}
	}
	return *this;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	std::cout << "MateriaSource copy constructor called." <<std::endl;
	*this = src;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called." <<std::endl;
	for (int i = 0; i < MATERIASOURCE_SIZE; ++i)
	{
		if (m_materiaSource[i])
		{
			delete m_materiaSource[i];
			m_materiaSource[i] = NULL;
		}
	}
}
