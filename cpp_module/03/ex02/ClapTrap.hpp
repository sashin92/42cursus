/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:30:46 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 10:30:46 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

# define C_DEFAULT_NAME "CT_Bot"
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

	void print(void) const;

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName(void) const;
	int getHitPoint(void) const;
	int getEnergyPoint(void) const;
	int getAttackDamage(void) const;

	void setName(std::string name);
	void setHitPoint(unsigned int hp);
	void setEnergyPoint(unsigned int ep);
	void setAttackDamage(unsigned int ad);

	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &clapTrap);
	ClapTrap &operator=(const ClapTrap &clapTrap);
	virtual ~ClapTrap();

};

#endif
