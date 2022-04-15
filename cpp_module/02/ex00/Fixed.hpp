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
	int m_fixedPoint;
	static const int m_fractionalBit = 8;

public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &fixed);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif
