/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:38:23 by sashin            #+#    #+#             */
/*   Updated: 2022/04/28 20:38:38 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>

// Base::Base(const Base &c);

Base::Base() {};

Base& Base::operator=(const Base& src)
{
	(void)src;
	return *this;
}

Base::~Base() {};

Base* generate(void)
{
	srand(time(0));
	int randomValue = rand() % 3;
	switch (randomValue)
	{
		case 0:
			std::cout << "A class generated." << std::endl;
			return new A();
		case 1:
			std::cout << "B class generated." << std::endl;
			return new B();
		case 2:
			std::cout << "C class generated." << std::endl;
			return new C();
	}
	return 0;
}

void identify(Base* p)
{
	if (dynamic_cast<A* >(p))
		std::cout << "this is A" << std::endl;
	else if (dynamic_cast<B* >(p))
		std::cout << "this is B" << std::endl;
	else if (dynamic_cast<C* >(p))
		std::cout << "this is C" << std::endl;
}

void identify(Base& p)
{
	Base tmp;

	try
	{
		tmp = dynamic_cast<A&>(p);
		std::cout << "this is A" << std::endl;
	}
	catch (std::exception& e){};
	try
	{
		tmp = dynamic_cast<B&>(p);
		std::cout << "this is B" << std::endl;
	}
	catch (std::exception& e){};
	try
	{
		tmp = dynamic_cast<C&>(p);
		std::cout << "this is C" << std::endl;
	}
	catch (std::exception& e){};

}
