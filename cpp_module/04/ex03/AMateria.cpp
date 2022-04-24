/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:40:22 by sashin            #+#    #+#             */
/*   Updated: 2022/04/24 15:40:22 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"


std::string const & AMateria::getType() const
{
	return m_type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "* Impossible to use *" <<std::endl;
}


AMateria::AMateria()
{
	std::cout << "AMateria constructor called. (default)" <<std::endl;
	m_type = "";
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "AMateria constructor called. (with type)" <<std::endl;
	m_type = type;
}

AMateria::AMateria(const AMateria &src)
{
	std::cout << "AMateria copy constructor called." <<std::endl;
	*this = src;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	std::cout << "AMateria copy assignment operator called." <<std::endl;
	if (this != &src)
	{
		m_type = src.m_type;
	}
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called." <<std::endl;
}

std::ostream& operator<<(std::ostream& os, const AMateria& type)
{
	return os << type.getType();
}
