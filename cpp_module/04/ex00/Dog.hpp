/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:09:58 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 18:09:58 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

# define D_DEFAULT_TYPE "Dog"

class Dog: public Animal
{
public:
	void makeSound() const;

	Dog();
	Dog(const Dog& dog);
	Dog &operator=(const Dog& dog);
	virtual ~Dog();
};

#endif
