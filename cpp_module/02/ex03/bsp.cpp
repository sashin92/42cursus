/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:39:20 by sashin            #+#    #+#             */
/*   Updated: 2022/04/20 14:39:21 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point operator-(const Point &p1, const Point &p2)
{
	return Point((p1.getX() - p2.getX()).toFloat(), (p1.getY() - p2.getY()).toFloat());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point ab = a - b;
	Point bc = b - c;
	Point ca = c - a;

	Point bp = b - point;
	Point cp = c - point;
	Point ap = a - point;

	Fixed ex1 = (ab.getX() * bp.getY()) - (bp.getX() * ab.getY());
	Fixed ex2 = (bc.getX() * cp.getY()) - (cp.getX() * bc.getY());
	Fixed ex3 = (ca.getX() * ap.getY()) - (ap.getX() * ca.getY());

	if ((ex1 > Fixed(0)) && (ex2 > Fixed(0)) && (ex3 > Fixed(0)))
		return true;
	else if ((ex1 < Fixed(0)) && (ex2 < Fixed(0)) && (ex3 < Fixed(0)))
		return true;
	return false;
}
