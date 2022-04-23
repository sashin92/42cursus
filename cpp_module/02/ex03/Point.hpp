/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:39:25 by sashin            #+#    #+#             */
/*   Updated: 2022/04/23 15:13:26 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	const Fixed m_x;
	const Fixed m_y;

public:
	Point();
	Point(const float &x, const float &y);
	Point(const Point &point);
	Point &operator=(const Point &point);
	~Point();

	const Fixed getX() const;
	const Fixed getY() const;

};

Point operator-(const Point &p1, const Point &p2);
bool bsp(Point const a, Point const b, Point const c, Point const point);

std::ostream &operator<<(std::ostream &os, const Point &point);

#endif
