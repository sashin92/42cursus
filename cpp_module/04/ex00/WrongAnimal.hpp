/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:47:36 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 18:47:36 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

# define WA_DEFAULT_TYPE "WrongAnimal"

class WrongAnimal
{
protected:
	std::string m_type;

public:
	void makeSound() const;

	std::string getType() const;
	void setType(std::string type);

	WrongAnimal();
	WrongAnimal(const WrongAnimal& wrongAnimal);
	WrongAnimal &operator=(const WrongAnimal& wrongAnimal);
	virtual ~WrongAnimal();
};

#endif
