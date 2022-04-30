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
# include <exception>

# include <algorithm>
# include <iterator>
# include <vector>

class Span
{
private:
	std::vector<int> m_integer;
	const unsigned int m_size;

	Span &operator=(const Span &src); // unused
	Span(); // unused
public:

	const unsigned int& getSize() const;
	const std::vector<int>& getInteger() const;

	void addNumber(int num);

	unsigned int shortestSpan();
	unsigned int longestSpan();

	void spanFiller(unsigned int size);


	Span(const unsigned int n);
	Span(const Span& src);
	~Span();
};



#endif
