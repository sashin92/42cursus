/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:39:23 by sashin            #+#    #+#             */
/*   Updated: 2022/04/20 15:20:04 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
: m_x(0), m_y(0)
{
}

Point::Point(const float &x, const float &y)
: m_x(x), m_y(y)
{
}

Point::Point(const Point &point)
{
	*this = point;
}

Point &Point::operator=(const Point &point)
{
	if (this != &point)
	{
		const_cast<Fixed &>(m_x) = point.getX();
		const_cast<Fixed &>(m_y) = point.getY();
	}
	return *this;
}

Point::~Point()
{
}

const Fixed Point::getX() const
{
	return this->m_x;
}

const Fixed Point::getY() const
{
	return this->m_y;
}

std::ostream &operator<<(std::ostream &os, const Point &point)
{
	return os << "(" << point.getX().toFloat() << ", " << point.getY().toFloat() << ")";
}
