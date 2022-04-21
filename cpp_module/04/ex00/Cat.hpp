/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:09:46 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 18:09:46 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

# define C_DEFAULT_TYPE "Cat"

class Cat: public Animal
{
public:
	void makeSound() const;

	Cat();
	Cat(const Cat& cat);
	Cat &operator=(const Cat& cat);
	virtual ~Cat();
};

#endif
