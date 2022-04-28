/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:07:15 by sashin            #+#    #+#             */
/*   Updated: 2022/04/28 18:46:37 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iomanip>
#include <limits>
#include "Converter.hpp"

void Converter::printChar()
{
	char cValue = static_cast<char>(m_dValue);
	std::cout << "char: ";
	if (isnan(m_dValue) || isinf(m_dValue))
		std::cout << "impossible" << std::endl;
	else if (m_dValue > std::numeric_limits<char>::max() || m_dValue < std::numeric_limits<char>::min())
		std::cout << "impossible" << std::endl;
	else if (!isprint(cValue))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << cValue << "'" << std::endl;
}

void Converter::printInt()
{
	int iValue = static_cast<int>(m_dValue);
	std::cout << "int: ";
	if (isnan(m_dValue) || isinf(m_dValue))
		std::cout << "impossible" << std::endl;
	else if (m_dValue > std::numeric_limits<int>::max() || m_dValue < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << iValue << std::endl;
}

void Converter::printFloat()
{
	float fValue = static_cast<float>(m_dValue);
	std::cout << "float: ";
	if (isinf(fValue))
		std::cout << std::showpos << fValue << "f" << std::endl;
	else if (fValue < powf(10, std::numeric_limits<float>::digits10) && fValue == static_cast<long long>(fValue))
		std::cout << std::setprecision(std::numeric_limits<float>::digits10) << fValue << ".0f" << std::endl;
	else
		std::cout << std::setprecision(std::numeric_limits<float>::digits10) << fValue << "f" << std::endl;
}

void Converter::printDouble()
{
	double dValue = static_cast<double>(m_dValue);
	std::cout << "double: ";
	if (isinf(dValue))
		std::cout << std::showpos << dValue << std::endl;
	else if (dValue < powl(10, std::numeric_limits<double>::digits10) && dValue == static_cast<long long>(dValue))
		std::cout << std::setprecision(std::numeric_limits<double>::digits10) << dValue << ".0" << std::endl;
	else
		std::cout << std::setprecision(std::numeric_limits<double>::digits10) << dValue << std::endl;
}

const char* Converter::InvalidInputException::what() const throw()
{
	return "Invalid input";
}

const std::string Converter::getInput() const
{
	return m_input;
}

bool Converter::getEFlag() const
{
	return m_eFlag;
}

// Converter::Converter(){}
// Converter &Converter::operator=(const Converter &src) {}
// Converter::Converter(const Converter &src) {}

Converter::Converter(const std::string& input)
: m_input(input)
{
	try
	{
		char *pt;

		m_dValue = strtod(m_input.c_str(), &pt);

		if (!m_input[0] || (m_dValue == 0.0 && m_input[0] != '-' && m_input[0] != '+' && !isdigit(m_input[0])))
			throw InvalidInputException();
		if (*pt && *pt == 'f')
			++pt;
		if (*pt)
			throw InvalidInputException();
	}
	catch (std::exception& e)
	{
		m_eFlag = true;
		std::cerr << e.what() << ": Use only that sign('-' or '+') and number." <<std::endl;
	}
}

Converter::~Converter() {}
