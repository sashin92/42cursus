/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:18:42 by sashin            #+#    #+#             */
/*   Updated: 2022/04/25 12:24:23 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void test1()
{
	std::cout << ">1. ------------------------" << std::endl;
	IMateriaSource* src = new MateriaSource();
	std::cout << ">2. ------------------------" << std::endl;
	src->learnMateria(new Ice());
	std::cout << ">3. ------------------------" << std::endl;
	src->learnMateria(new Cure());

	std::cout << ">4. ------------------------" << std::endl;
	ICharacter* me = new Character("me");

	std::cout << ">5. ------------------------" << std::endl;
	AMateria* tmp;
	std::cout << ">6. ------------------------" << std::endl;
	tmp = src->createMateria("ice");
	std::cout << ">7. ------------------------" << std::endl;
	me->equip(tmp);
	std::cout << ">8. ------------------------" << std::endl;
	tmp = src->createMateria("cure");
	std::cout << ">9. ------------------------" << std::endl;
	me->equip(tmp);

	std::cout << ">10. ------------------------" << std::endl;
	ICharacter* bob = new Character("bob");

	std::cout << ">11. ------------------------" << std::endl;
	me->use(0, *bob);
	std::cout << ">12. ------------------------" << std::endl;
	me->use(1, *bob);

	std::cout << ">13. ------------------------" << std::endl;
	delete bob;
	std::cout << ">14. ------------------------" << std::endl;
	delete me;
	std::cout << ">15. ------------------------" << std::endl;
	delete src;
	std::cout << ">16. ------------------------" << std::endl;
}

void test2()
{
	std::cout << ">---------test2---------------" << std::endl;
	std::cout << ">0. ------------------------" << std::endl;
	IMateriaSource* src = new MateriaSource();
	AMateria* tmp;
	tmp = src->createMateria("ice");
	std::cout << ">1. ------------------------" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(NULL);
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	std::cout << ">2. ------------------------" << std::endl;
	tmp = src->createMateria("icecure");

	std::cout << ">3. ------------------------" << std::endl;
	ICharacter* noName = new Character();
	ICharacter* bob = new  Character("bob");

	std::cout << ">4. ------------------------" << std::endl;
	tmp = src->createMateria("ice");
	noName->equip(tmp);
	tmp = src->createMateria("cure");
	noName->equip(tmp);

	std::cout << ">5. ------------------------" << std::endl;
	AMateria* tmp1 = src->createMateria("ice");
	noName->equip(tmp1);
	AMateria* tmp2 = src->createMateria("cure");
	noName->equip(tmp2);

	std::cout << ">6. ------------------------" << std::endl;
	noName->unequip(2);
	noName->unequip(3);

	std::cout << ">7. ------------------------" << std::endl;
	bob->equip(tmp1);
	bob->equip(tmp2);

	std::cout << ">8. ------------------------" << std::endl;
	noName->use(0, *bob);
	noName->use(1, *bob);

	std::cout << ">9. ------------------------" << std::endl;
	bob->use(0, *noName);
	bob->use(1, *noName);

	std::cout << ">10. ------------------------" << std::endl;
	delete bob;
	std::cout << ">11. ------------------------" << std::endl;
	delete noName;
	std::cout << ">12. ------------------------" << std::endl;
	delete src;
	std::cout << ">13. ------------------------" << std::endl;
}

int main()
{
	test1();
	test2();
	system("leaks a.out");
	return 0;
}
