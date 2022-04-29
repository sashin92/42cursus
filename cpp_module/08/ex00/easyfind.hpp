/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:44:16 by sashin            #+#    #+#             */
/*   Updated: 2022/04/29 18:42:49 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>
# include <iterator>
# include <iostream>


class CannotFindException: public std::exception
{
	const char* what() const throw()
	{
		return "cannot find the value";
	}
};

template<typename T>
typename T::iterator easyfind(T& t, int i)
{
	typename T::iterator iter;

	iter = std::find(t.begin(), t.end(), i);

	if (iter == t.end())
		throw CannotFindException();

	return iter;
}

#endif
