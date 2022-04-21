/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:09:56 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 18:09:56 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

void Dog::makeSound() const
{
	std::cout << "Bark!" << std::endl;
}

Dog::Dog()
: Animal()
{
	std::cout << "Dog default constructor executed." << std::endl;
	this->m_type = D_DEFAULT_TYPE;
}

Dog::Dog(const Dog& dog)
: Animal()
{
	std::cout << "Dog copy constructor executed." << std::endl;
	this->m_type = dog.getType();
}

Dog &Dog::operator=(const Dog& dog)
{
	std::cout << "Dog assignment operator overload executed." << std::endl;
	if (this != &dog)
		this->m_type = dog.getType();
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor executed." << std::endl;
}
