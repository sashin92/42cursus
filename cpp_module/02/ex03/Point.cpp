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

Point::Point(const float x, const float y)
: m_x(x), m_y(y)
{
}


Point::Point(const Point &point)
{
	this->m_x = point.getX();
	this->m_y = point.getY();
}

Point &Point::operator=(const Point *point)
{
	this->m_x = point->m_x;
}

Point::~Point()
{
	
}

Fixed Point::getX()
{
	return this->m_x;
}

Fixed Point::getY()
{
	return this->m_y;
}
