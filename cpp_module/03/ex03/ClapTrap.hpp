/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:30:46 by sashin            #+#    #+#             */
/*   Updated: 2022/04/23 17:37:43 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

# define DEFAULT_NAME "Default_Bot"
# define C_DEFAULT_HP 10
# define C_DEFAULT_EP 10
# define C_DEFAULT_AD 0

class ClapTrap
{
protected:
	std::string m_name;
	unsigned int m_hitPoint;
	unsigned int m_energyPoint;
	unsigned int m_attackDamage;

public:
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	virtual std::string getName(void) const;

	int getHitPoint(void) const;
	int getEnergyPoint(void) const;
	int getAttackDamage(void) const;

	void setName(std::string name);
	void setHitPoint(unsigned int hp);
	void setEnergyPoint(unsigned int ep);
	void setAttackDamage(unsigned int ad);

	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &clapTrap);
	ClapTrap &operator=(const ClapTrap &clapTrap);
	virtual ~ClapTrap();
};

std::ostream& operator<<(std::ostream& os, const ClapTrap& c);

#endif
