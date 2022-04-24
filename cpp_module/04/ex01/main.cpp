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

void testDeepCopy()
{
	Dog* testDog = new Dog();
	Cat* testCat1 = new Cat();
	Cat* testCat2 = new Cat();

	// deep copy using assign.operator
	testCat1->setType("TESTCAT_1");
	std::cout << "\n---------- deep copy using assign.operator ----------" << std::endl;
	std::cout << "testCat1: " << testCat1->getType() << std::endl;
	std::cout << "testCat2: " << testCat2->getType() << std::endl;
	*testCat2 = *testCat1;
	std::cout << "testCat1: " << testCat1->getType() << std::endl;
	std::cout << "testCat2: " << testCat2->getType() << std::endl;
	testCat2->setType("TESTCAT_2");
	std::cout << "testCat1: " << testCat1->getType() << std::endl;
	std::cout << "testCat2: " << testCat2->getType() << std::endl;

	// deep copy using copy operator
	std::cout << "\n---------- deep copy using copy operator ----------" << std::endl;
	Cat* testCat3 = new Cat(*testCat1);
	
	std::cout << std::endl;
	std::cout << "testCat1: " << testCat1->getType() << std::endl;
	std::cout << "testCat3: " << testCat3->getType() << std::endl;
	testCat3->setType("TESTCAT_3");
	std::cout << "testCat1: " << testCat1->getType() << std::endl;
	std::cout << "testCat3: " << testCat3->getType() << std::endl;

	std::cout << std::endl;
	delete testDog;
	delete testCat1;
	delete testCat2;
	delete testCat3;

}

void testArrayCheck()
{
	Animal* testAnimal[6];

	for (int i = 0; i < 6; i++)
	{
		if (i % 2)
			testAnimal[i] = new Dog();
		else
			testAnimal[i] = new Cat();
	}
	
	for (int i = 0; i < 6; i++)
	{
		delete testAnimal[i];
	}
}

void testBrainCheck()
{
	Dog* testDog;

	testDog = new Dog();

	std::cout << std::endl;
	std::cout << *testDog->getBrain() << std::endl;

	std::cout << std::endl;
	delete testDog;
}

int main()
{
	std::cout << "\n===========subject_test===========" << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	std::cout << "\n===========test1===========" << std::endl;
	testDeepCopy();
	std::cout << "\n===========test2===========" << std::endl;
	testArrayCheck();
	std::cout << "\n===========test3===========" << std::endl;
	testBrainCheck();
	std::cout << "\n===========test4===========" << std::endl;
	Animal test4;

	return 0;
}
