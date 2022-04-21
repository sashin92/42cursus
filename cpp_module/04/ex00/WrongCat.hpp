/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:48:21 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 18:48:21 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

# define WC_DEFAULT_TYPE "WrongCat"

class WrongCat: public WrongAnimal
{
public:
	void makeSound() const;

	WrongCat();
	WrongCat(const WrongCat& wrongCat);
	WrongCat &operator=(const WrongCat& wrongCat);
	virtual ~WrongCat();
};

#endif
