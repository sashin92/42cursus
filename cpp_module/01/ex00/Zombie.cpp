/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:34:26 by sashin            #+#    #+#             */
/*   Updated: 2022/01/18 11:34:26 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name )
{
	this->m_name = name;
	this->announce();
}

Zombie::~Zombie()
{
	std::cout << this->m_name << " is dead.\n";
}

void Zombie::announce( void )
{
	std::cout << this->m_name << ": BraiiiiiiinnnzzzZ...\n";
}
