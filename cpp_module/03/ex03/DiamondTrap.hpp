/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:57:51 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 15:57:51 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

# define D_DEFAULT_NAME "DT_Bot"

class DiamondTrap: public FragTrap, public ScavTrap
{
private:
	std::string m_name;

public:
	void attack(const std::string &target);

	void whoAmI();

	std::string getName(void) const;
	
	DiamondTrap();
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &diamondTrap);
	DiamondTrap &operator=(const DiamondTrap &diamondTrap);
	virtual ~DiamondTrap();

};

#endif