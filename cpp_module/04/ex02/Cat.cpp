/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:09:48 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 18:09:48 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

void Cat::makeSound() const
{
	std::cout << "Meow." << std::endl;
}

Brain* Cat::getBrain() const
{
	return this->m_brain;
}

Cat::Cat()
{
	std::cout << "Cat default constructor executed." << std::endl;
	this->m_type = C_DEFAULT_TYPE;
	this->m_brain = new Brain();
}

Cat::Cat(const Cat& cat)
{
	std::cout << "Cat copy constructor executed." << std::endl;
	this->m_brain = new Brain(*cat.getBrain());
	this->m_type = cat.getType();
}

Cat &Cat::operator=(const Cat& cat)
{
	std::cout << "Cat assignment operator overload executed." << std::endl;
	if (this != &cat)
	{
		this->m_type = cat.getType();
		if (this->m_brain)
			delete this->m_brain;
		this->m_brain = new Brain();
	}
	return *this;
}

Cat::~Cat()
{
	delete this->m_brain;
	std::cout << "Cat destructor executed." << std::endl;
}
