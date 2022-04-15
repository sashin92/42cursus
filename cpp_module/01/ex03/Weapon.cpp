/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:25:51 by sashin            #+#    #+#             */
/*   Updated: 2022/01/18 14:25:51 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type)
: m_type(type)
{
}

Weapon::~Weapon()
{
}

std::string Weapon::getType()
{
	return (this->m_type);
}

void Weapon::setType(std::string type)
{
	this->m_type = type;
}
