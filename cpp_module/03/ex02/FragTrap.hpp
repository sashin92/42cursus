/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:09:57 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 15:09:57 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# define F_DEFAULT_NAME "FT_Bot"
# define F_DEFAULT_HP 100
# define F_DEFAULT_EP 100
# define F_DEFAULT_AD 30

class FragTrap: public ClapTrap
{
public:
	void attack(const std::string &target);

	void highFivesGuys(void);

	FragTrap();
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &fragTrap);
	FragTrap &operator=(const FragTrap &fragTrap);
	virtual ~FragTrap();

};


#endif
