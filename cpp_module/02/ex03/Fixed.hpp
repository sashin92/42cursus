/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:14:49 by sashin            #+#    #+#             */
/*   Updated: 2022/01/18 23:14:49 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int m_fixedPoint;
	static const int m_fractionalBit = 8;

public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &fixed);
	~Fixed();

	Fixed(const int d);
	Fixed(const float num);

	float toFloat( void ) const;
	int toInt( void ) const;

	int getRawBits( void ) const;
	void setRawBits( int const raw );

	Fixed &operator++(void);
	Fixed &operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);

	static const Fixed &max(const Fixed &a, const Fixed &b);

};

bool operator>(const Fixed &lhs, const Fixed &rhs);
bool operator<(const Fixed &lhs, const Fixed &rhs);
bool operator>=(const Fixed &lhs, const Fixed &rhs);
bool operator<=(const Fixed &lhs, const Fixed &rhs);
bool operator==(const Fixed &lhs, const Fixed &rhs);
bool operator!=(const Fixed &lhs, const Fixed &rhs);

Fixed operator+(const Fixed &lhs, const Fixed &rhs);
Fixed operator-(const Fixed &lhs, const Fixed &rhs);
Fixed operator*(const Fixed &lhs, const Fixed &rhs);
Fixed operator/(const Fixed &lhs, const Fixed &rhs);

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
