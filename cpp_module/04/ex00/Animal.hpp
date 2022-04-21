/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:37:25 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 17:37:25 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# define A_DEFAULT_TYPE "Animal"

class Animal
{
protected:
	std::string m_type;

public:
	virtual void makeSound() const;

	std::string getType() const;
	void setType(std::string type);

	Animal();
	Animal(const Animal& animal);
	Animal &operator=(const Animal& animal);
	virtual ~Animal();
};

#endif
