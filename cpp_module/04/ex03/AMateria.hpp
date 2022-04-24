/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:40:25 by sashin            #+#    #+#             */
/*   Updated: 2022/04/24 15:40:25 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>

class ICharacter;

class AMateria
{
protected:
	std::string m_type;

public:
	std::string const & getType() const; //Returns the materia type

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria &src);
	AMateria &operator=(const AMateria &src);
	virtual ~AMateria();
};

std::ostream& operator<<(std::ostream& os, const AMateria& type);

#endif
