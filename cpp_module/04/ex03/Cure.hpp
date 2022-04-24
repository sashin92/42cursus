/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:45:22 by sashin            #+#    #+#             */
/*   Updated: 2022/04/24 15:45:22 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <string>
# include "AMateria.hpp"

# define C_TYPE "cure"

class Cure: public AMateria
{
public:
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);

	Cure();
	Cure(const Cure &src);
	Cure &operator=(const Cure &src);
	~Cure();
};

#endif
