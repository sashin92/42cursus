/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:46:22 by sashin            #+#    #+#             */
/*   Updated: 2022/04/29 19:08:41 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void Span::addNumber(int num)
{
	m_integer.push_back(num);
}


Span::Span(unsigned int n)
{
	
}


Span& Span::shortestSpan();
Span& Span::longestSpan();
