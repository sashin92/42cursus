/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:15:50 by sashin            #+#    #+#             */
/*   Updated: 2022/01/18 23:15:50 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen()
{
}

Karen::~Karen()
{
}

void Karen::debug( void )
{
	std::cout << "DEBUG: " 
			<< "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. "
			<< "I just love it!\n";
}

void Karen::info( void ){
	std::cout << "INFO: "
			<< "I cannot believe adding extra bacon cost more money. "
			<< "You don't put enough! If you did I would not have to ask for it!\n";
}

void Karen::warning( void ){
	std::cout << "WARINING: "
			<< "I think I deserve to have some extra bacon for free. "
			<< "I've been coming here for years and you just started working here last month.\n";
}

void Karen::error( void ){
	std::cout << "ERROR: "
			<< "This is unacceptable, I want to speak to the manager now.\n";
}

void Karen::complain( std::string level )
{
	void (Karen::*value[4])();
	std::string key[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	value[0] = &Karen::debug;
	value[1] = &Karen::info;
	value[2] = &Karen::warning;
	value[3] = &Karen::error;

	bool checkLevel = false;
	for (int i = 0; i < 4; i++)
	{
		if (checkLevel || key[i] == level)
		{
			checkLevel = true;
			(this->*value[i])();
		}
	}
	if (!checkLevel)
		std::cout << "[ Probably complaining about insignificant problems ]\n";
}