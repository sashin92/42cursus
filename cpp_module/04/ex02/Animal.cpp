/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:37:27 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 17:37:27 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

std::string Animal::getType() const
{
	return this->m_type;
}

void Animal::setType(std::string type)
{
	this->m_type = type;
}

Animal::Animal()
: m_type(A_DEFAULT_TYPE)
{
	std::cout << "Animal default constructor executed." << std::endl;
}

Animal::Animal(const Animal& animal)
{
	std::cout << "Animal copy constructor executed." << std::endl;
	*this = animal;
}

Animal &Animal::operator=(const Animal& animal)
{
	std::cout << "Animal assignment operator overload executed." << std::endl;
	if (this != &animal)
		this->m_type = animal.getType();
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor executed." << std::endl;
}
