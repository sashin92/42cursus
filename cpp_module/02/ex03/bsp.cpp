/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:39:20 by sashin            #+#    #+#             */
/*   Updated: 2022/04/23 19:31:23 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point operator-(const Point &p1, const Point &p2)
{
	return Point((p1.getX() - p2.getX()).toFloat(), (p1.getY() - p2.getY()).toFloat());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point ab(b - a);
	Point bc(c - b);
	Point ca(a - c);

	Point bp(point - b);
	Point cp(point - c);
	Point ap(point - a);

	Point ba(a - b);
	Point cb(b - c);
	Point ac(c - a);
	
	Fixed ex1 = (ab.getX() * bp.getY()) - (bp.getX() * ab.getY());
	Fixed ex2 = (bc.getX() * cp.getY()) - (cp.getX() * bc.getY());
	Fixed ex3 = (ca.getX() * ap.getY()) - (ap.getX() * ca.getY());
	
	Fixed ex4 = (ba.getX() * ap.getY()) - (ap.getX() * ba.getY());
	Fixed ex5 = (cb.getX() * bp.getY()) - (bp.getX() * cb.getY());
	Fixed ex6 = (ac.getX() * cp.getY()) - (cp.getX() * ac.getY());

	if ((ex1 > Fixed(0)) && (ex2 > Fixed(0)) && (ex3 > Fixed(0))
		&& (ex4 < Fixed(0)) && (ex5 < Fixed(0)) && (ex6 < Fixed(0)))
		return true;
	else if ((ex1 < Fixed(0)) && (ex2 < Fixed(0)) && (ex3 < Fixed(0))
		&& (ex4 > Fixed(0)) && (ex5 > Fixed(0)) && (ex6 > Fixed(0)))
		return true;
	return false;
}
