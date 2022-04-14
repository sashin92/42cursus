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

class Fixed
{
private:
	int _fixedPoint;
	static const int _fractionalBit = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &fixed);
	Fixed(const float num);
	Fixed(const int num);
	Fixed &operator=(const Fixed &fixed);
	Fixed &operator<<( void );

	float toFloat( void ) const;
	int toInt( void ) const;

	int getRawBits( void ) const;
	void setRawBits( int const raw );

};

#endif
