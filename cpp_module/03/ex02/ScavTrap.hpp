/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:34:47 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 13:34:47 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# define S_DEFAULT_NAME "ST_Bot"
# define S_DEFAULT_HP 100
# define S_DEFAULT_EP 50
# define S_DEFAULT_AD 20


class ScavTrap: public ClapTrap
{
public:
	void attack(const std::string &target);

	void guardGate(void) const;

	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &scavTrap);
	ScavTrap& operator=(const ScavTrap &scavTrap);
	virtual ~ScavTrap();


};

#endif
