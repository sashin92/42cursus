/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:48:17 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 18:48:17 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

void WrongCat::makeSound() const
{
	std::cout << "Meow..?" << std::endl;
}

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor executed." << std::endl;
	this->m_type = WC_DEFAULT_TYPE;
}

WrongCat::WrongCat(const WrongCat& wrongCat)
{
	std::cout << "WrongCat copy constructor executed." << std::endl;
	this->m_type = wrongCat.getType();
}

WrongCat &WrongCat::operator=(const WrongCat& wrongCat)
{
	std::cout << "WrongCat assignment operator overload executed." << std::endl;
	if (this != &wrongCat)
		this->m_type = wrongCat.getType();
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor executed." << std::endl;
}
