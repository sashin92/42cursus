/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:07:15 by sashin            #+#    #+#             */
/*   Updated: 2022/04/28 20:34:52 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

std::string Data::getStr() const
{
	return m_str;
}

int Data::getInt() const
{
	return m_int;
}

double Data::getDouble() const
{
	return m_double;
}

// Data &Data::operator=(const Data &src) {}
// Data::Data(const Data &src) {}

Data::Data()
: m_str("default_str"), m_int(42), m_double(4242.42)
{
}

Data::Data(std::string str, int i, double d)
{
	m_str = str;
	m_int = i;
	m_double = d;
}

Data::~Data() {}

uintptr_t serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
  return reinterpret_cast<Data* >(raw);
}

void printPtr(uintptr_t raw)
{
	Data *data = deserialize(raw);
	if (!data)
		return ;
	std::cout << "str: " << data->getStr()
	<< "\nint: " << data->getInt()
	<< "\ndouble: " << data->getDouble() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Data& d)
{
	return os << "str: " << d.getStr()
	<< "\nint: " << d.getInt()
	<< "\ndouble: " << d.getDouble();
}
