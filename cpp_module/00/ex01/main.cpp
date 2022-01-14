/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:57:23 by sashin            #+#    #+#             */
/*   Updated: 2022/01/06 13:57:23 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "phone_book.hpp"

int	main(void)
{
	std::string		input;
	PhoneBook		phone_book;

	while (1)
	{
		if (std::cin.eof())
		{
			std::cout << "\nbye\n";
			return 0;
		}
		std::cout << "Please input correct keyword[ADD, SEARCH, EXIT]\n> ";
		std::cin >> input;
		if (input == "ADD")
		{
			std::cout << "ADD!\n";
			phone_book.Add();
		}
		else if (input == "SEARCH")
		{
			std::cout << "SEARCH!\n";
			phone_book.Search();
		}
		else if (input == "EXIT")
		{
			std::cout << "bye\n";
			return 0;
		}
	}
	return 0;
}
