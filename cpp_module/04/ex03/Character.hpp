/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:42:01 by sashin            #+#    #+#             */
/*   Updated: 2022/04/24 16:42:01 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
#include <iostream>
# include "ICharacter.hpp"

# define INVENTORY_SIZE 4
# define DEFAULT_NAME "NoName"

class AMateria;

class Character: public ICharacter
{
private:
	AMateria* m_materiaInventory[INVENTORY_SIZE];
	std::string m_name;

public:
	const AMateria* getMateria(int idx) const;

	const std::string & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);


	Character();
	Character(const std::string& name);
	Character(const Character &src);
	Character &operator=(const Character &src);
	~Character();

};

#endif
