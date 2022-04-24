/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:45:29 by sashin            #+#    #+#             */
/*   Updated: 2022/04/24 15:45:29 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <string>
# include "AMateria.hpp"

# define I_TYPE "ice"

class Ice: public AMateria
{
public:
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);

	Ice();
	Ice(const Ice &src);
	Ice &operator=(const Ice &src);
	~Ice();
};

#endif
