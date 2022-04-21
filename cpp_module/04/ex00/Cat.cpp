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

Cat::Cat()
: Animal()
{
	std::cout << "Cat default constructor executed." << std::endl;
	this->m_type = C_DEFAULT_TYPE;
}

Cat::Cat(const Cat& cat)
: Animal()
{
	std::cout << "Cat copy constructor executed." << std::endl;
	this->m_type = cat.getType();
}

Cat &Cat::operator=(const Cat& cat)
{
	std::cout << "Cat assignment operator overload executed." << std::endl;
	if (this != &cat)
		this->m_type = cat.getType();
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor executed." << std::endl;
}
