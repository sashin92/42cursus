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

Brain* Dog::getBrain() const
{
	return this->m_brain;
}

Dog::Dog()
{
	std::cout << "Dog default constructor executed." << std::endl;
	this->m_type = D_DEFAULT_TYPE;
	this->m_brain = new Brain();
}

Dog::Dog(const Dog& dog)
{
	std::cout << "Dog copy constructor executed." << std::endl;
	*this = dog;
}

Dog &Dog::operator=(const Dog& dog)
{
	std::cout << "Dog assignment operator overload executed." << std::endl;
	if (this != &dog)
	{
		this->m_type = dog.getType();
		if (this->m_brain)
			delete this->m_brain;
		this->m_brain = new Brain();
	}
	return *this;
}

Dog::~Dog()
{
	delete this->m_brain;
	std::cout << "Dog destructor executed." << std::endl;
}
