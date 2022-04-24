/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:45:24 by sashin            #+#    #+#             */
/*   Updated: 2022/04/24 15:45:24 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

AMateria* Cure::clone() const
{
	return new Cure();
}


void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *"<< std::endl;
}

Cure::Cure()
{
	std::cout << "Cure constructor called. (default)" <<std::endl;
	this->m_type = C_TYPE;
}

Cure::Cure(const Cure &a)
{
	std::cout << "Cure copy constructor called." <<std::endl;
	*this = a;
}

Cure &Cure::operator=(const Cure &c)
{
	std::cout << "Cure copy assignment operator called." <<std::endl;
	if (this != &c)
	{
		this->m_type = c.m_type;
	}
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called." <<std::endl;
}
