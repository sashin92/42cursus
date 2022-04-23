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
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const int d)
{
	this->m_fixedPoint = d * (1 << this->m_fractionalBit);
}

Fixed::Fixed(const float f)
{
	this->m_fixedPoint = static_cast<int>(roundf(f * (1 << this->m_fractionalBit)));
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
	{
		this->m_fixedPoint = fixed.m_fixedPoint;
	}
	return *this;
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->m_fixedPoint) / static_cast<float>(1 << this->m_fractionalBit));
}

int Fixed::toInt( void ) const
{
	return (this->m_fixedPoint / (1 << this->m_fractionalBit));
}

int Fixed::getRawBits( void ) const
{
	return this->m_fixedPoint;
}

void Fixed::setRawBits( int const raw )
{
	this->m_fixedPoint = raw;
}



bool operator>(const Fixed &lhs, const Fixed &rhs)
{
	return lhs.getRawBits() > rhs.getRawBits();
}

bool operator<(const Fixed &lhs, const Fixed &rhs)
{
	return lhs.getRawBits() < rhs.getRawBits();
}

bool operator>=(const Fixed &lhs, const Fixed &rhs)
{
	return lhs.getRawBits() >= rhs.getRawBits();
}

bool operator<=(const Fixed &lhs, const Fixed &rhs)
{
	return lhs.getRawBits() <= rhs.getRawBits();
}

bool operator==(const Fixed &lhs, const Fixed &rhs)
{
	return lhs.getRawBits() == rhs.getRawBits();
}

bool operator!=(const Fixed &lhs, const Fixed &rhs)
{
	return lhs.getRawBits() != rhs.getRawBits();
}

Fixed operator+(const Fixed &lhs, const Fixed &rhs)
{
	Fixed ret(lhs.toFloat() + rhs.toFloat());
	return ret;
}

Fixed operator-(const Fixed &lhs, const Fixed &rhs)
{
	Fixed ret(lhs.toFloat() - rhs.toFloat());
	return ret;
}

Fixed operator*(const Fixed &lhs, const Fixed &rhs)
{
	Fixed ret(lhs.toFloat() * rhs.toFloat());
	return ret;
}

Fixed operator/(const Fixed &lhs, const Fixed &rhs)
{
	Fixed ret(lhs.toFloat() / rhs.toFloat());
	return ret;
}

Fixed &Fixed::operator++(void)
{
	++(this->m_fixedPoint);
	return *this;
}

Fixed &Fixed::operator--(void)
{
	--(this->m_fixedPoint);
	return *this;
}

const Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++(this->m_fixedPoint);
	return tmp;
}

const Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--(this->m_fixedPoint);
	return tmp;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}


std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	return os << fixed.toFloat();
}

