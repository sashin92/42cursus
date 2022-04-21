/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:37:06 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 17:37:06 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	meta->makeSound();
	i->makeSound(); //will output the cat sound!
	j->makeSound();

	std::cout << "-------------" << std::endl;
	const WrongAnimal* wMeta = new WrongAnimal();
	const WrongAnimal* wCat = new WrongCat();
	std::cout << wCat->getType() << " " << std::endl;
	wCat->makeSound();
	wMeta->makeSound();

	return 0;
}
