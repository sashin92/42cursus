/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:02:39 by sashin            #+#    #+#             */
/*   Updated: 2022/01/18 15:02:39 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
private:
	Weapon &m_weapon;
	std::string m_name;
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack();
};

#endif
