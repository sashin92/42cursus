/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:15:50 by sashin            #+#    #+#             */
/*   Updated: 2022/01/18 23:15:50 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
: m_fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const int num)
: m_fixedPoint(num)
{
	std::cout << "Int constructor called" << std::endl;
	this->m_fixedPoint <<= this->m_fractionalBit;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
	{
		std::cout << "Assignation operator called" << std::endl;
		this->m_fixedPoint = fixed.getRawBits();
	}
	return *this;
}

// Fixed &Fixed::operator<<( void )
// {
// 	std::cout << Fixed::getRawBits();
// }

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->m_fixedPoint) / (1 << this->m_fractionalBit));
}

int Fixed::toInt( void ) const
{
	return (this->m_fixedPoint >> this->m_fractionalBit);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->m_fixedPoint;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->m_fixedPoint = raw;
}
