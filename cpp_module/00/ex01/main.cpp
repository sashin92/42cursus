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
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook		phone_book;
	std::string		input;

	while (true)
	{
		if (std::cin.eof())
		{
			std::cout << "\nbye\n";
			return 0;
		}
		std::cout << "Please input correct keyword[ADD, SEARCH, EXIT]\n> ";
		std::getline(std::cin, input);
		input.erase(0, input.find_first_not_of(" \t\n\v\f\r"));
		input.erase(input.find_last_not_of(" \t\n\v\f\r") + 1);
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
