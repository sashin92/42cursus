/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:46:40 by sashin            #+#    #+#             */
/*   Updated: 2022/04/29 19:10:08 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>

# include <algorithm>
# include <iterator>
# include <vector>

class Span
{
private:
	std::vector<int>m_integer;
	unsigned int 

	Span(); // unused
	Span &operator=(const Span &c); // unused
	Span(const Span &c); // unused
public:

	void addNumber(int num);

	Span& shortestSpan();
	Span& longestSpan();

	Span(unsigned int n);
	~Span();
};



#endif
