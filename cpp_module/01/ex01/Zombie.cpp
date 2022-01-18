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
	this->name = name;
	this->announce();
}

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << this->name << " is dead.\n";
}

void Zombie::announce( void ) const
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ...\n";
}
