/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:45:26 by sashin            #+#    #+#             */
/*   Updated: 2022/04/24 15:45:26 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

AMateria* Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"<< std::endl;
}

Ice::Ice()
{
	std::cout << "Ice constructor called. (default)" <<std::endl;
	m_type = I_TYPE;
}

Ice::Ice(const Ice &a)
{
	std::cout << "Ice copy constructor called." <<std::endl;
	*this = a;
}

Ice &Ice::operator=(const Ice &i)
{
	std::cout << "Ice copy assignment operator called." <<std::endl;
	if (this != &i)
	{
		this->m_type = i.m_type;
	}
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called." <<std::endl;
}
