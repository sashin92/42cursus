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

# include "Animal.hpp"
# include "Brain.hpp"

# define D_DEFAULT_TYPE "Dog"

class Dog: public Animal
{
private:
	Brain* m_brain;

public:
	void makeSound() const;

	Brain* getBrain() const;

	Dog();
	Dog(const Dog& dog);
	Dog &operator=(const Dog& dog);
	virtual ~Dog();
};

#endif
