/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:55:36 by sashin            #+#    #+#             */
/*   Updated: 2022/04/29 10:58:48 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<class T>
T min(T& a, T& b)
{
	if (a < b)
		return a;
	return b;
}

template<class T>
T max(T& a, T& b)
{
	if (a > b)
		return a;
	return b;
}

#endif
