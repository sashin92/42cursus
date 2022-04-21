/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:47:30 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 18:47:30 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

void WrongAnimal::makeSound() const
{
	std::cout << "this is 'Wrong' DEFAULT Sound." << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->m_type;
}

void WrongAnimal::setType(std::string type)
{
	this->m_type = type;
}

WrongAnimal::WrongAnimal()
: m_type(WA_DEFAULT_TYPE)
{
	std::cout << "WrongAnimal default constructor executed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal)
{
	std::cout << "WrongAnimal copy constructor executed." << std::endl;
	*this = wrongAnimal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& wrongAnimal)
{
	std::cout << "WrongAnimal assignment operator overload executed." << std::endl;
	if (this != &wrongAnimal)
		this->m_type = wrongAnimal.getType();
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor executed." << std::endl;
}
