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

#include <numeric>
#include <stdexcept>
#include <stdlib.h>
#include "Span.hpp"

const unsigned int& Span::getSize() const
{
	return m_size;
}


const std::vector<int>& Span::getInteger() const
{
	return m_integer;
}

void Span::addNumber(int num)
{
	if (m_integer.size() == m_size)
		throw std::out_of_range("out of range!");
	if (std::find(m_integer.begin(), m_integer.end(), num) != m_integer.end())
		throw std::logic_error("input element is already exist in array");
	m_integer.push_back(num);
}

unsigned int Span::shortestSpan()
{
	if (m_integer.size() <= 1)
		throw std::logic_error("At least two numbers are required in Span");
	std::vector<int> sortedInteger(m_integer);
	std::vector<int> diffedInteger;
	std::sort(sortedInteger.begin(), sortedInteger.end());
	std::adjacent_difference(sortedInteger.begin(), sortedInteger.end(), std::back_inserter(diffedInteger));
	std::vector<int>::iterator iter = std::min_element(++diffedInteger.begin(), diffedInteger.end());
	return *(iter);
}

unsigned int Span::longestSpan()
{
	if (m_integer.size() <= 1)
		throw std::logic_error("At least two numbers are required in Span");
	std::vector<int>::iterator iterMin, iterMax;
	iterMin = std::min_element(m_integer.begin(), m_integer.end());
	iterMax = std::max_element(m_integer.begin(), m_integer.end());
	return (*iterMax - *iterMin);
}

void Span::spanFiller(unsigned int size)
{
	unsigned int dupCount = 0;

	srand(time(0));
	for (unsigned int i = 0; i < size; i++)
	{
		try
		{
			addNumber(rand());
		}
		catch (std::exception& e)
		{
			std::cout << ++dupCount << ": " << e.what() << std::endl;
		}
	}
}

Span::Span(const unsigned int n)
: m_integer(0), m_size(n)
{
	m_integer.reserve(n);
}

Span::Span(const Span& src)
: m_integer(0), m_size(src.m_size)
{
	m_integer.reserve(src.m_size);
	std::copy(src.m_integer.begin(), src.m_integer.end(), std::back_inserter(m_integer));
}

Span::~Span() {}
