/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:06:49 by sashin            #+#    #+#             */
/*   Updated: 2022/04/29 10:54:58 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void toLower(char& c)
{
	c += 32;
}

void suffixAdder(std::string& s)
{
	s += "world";
}

int main()
{
	char c[4] = {'H', 'E', 'L', 'O'};
	
	std::cout << c << std::endl;
	iter(c, 4, toLower);
	std::cout << c << std::endl;

	std::cout << "------------------" << std::endl;
	
	std::string str[3] = {"hello", "sashin", "42"};

	iter(str, 3, suffixAdder);
	for (int i = 0; i < 3; i++)
		std::cout << str[i] << std::endl;


	return 0;

}
