/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:26:26 by sashin            #+#    #+#             */
/*   Updated: 2022/01/06 13:26:26 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contactSize = 0;
}


PhoneBook::~PhoneBook()
{
}

namespace {

void printTenLength(std::string str)
{
	if (str.size() > 10)
		std::cout << std::setw(9) << str.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << str << "|";
}

bool stringIsDigit(std::string str)
{
	for(size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

}

void PhoneBook::Add()
{
	std::string	tmp;
	int			idx;

	if (this->contactSize == 8)
	{
		idx = this->contactSize - 1;
		for (int i = 0; i < 7; i++)
		{
			this->contacts[i] = this->contacts[i + 1];
		}
	}
	else
	{
		idx = this->contactSize;
		this->contactSize += 1;
	}
	std::cout << "First Name? ";
	std::getline(std::cin, tmp);
	this->contacts[idx].SetFirstName(tmp);
	std::cout << "Last Name? ";
	std::getline(std::cin, tmp);
	this->contacts[idx].SetLastName(tmp);
	std::cout << "Nick Name? ";
	std::getline(std::cin, tmp);
	this->contacts[idx].SetNickName(tmp);
	std::cout << "Phone Number? ";
	std::getline(std::cin, tmp);
	this->contacts[idx].SetPhoneNumber(tmp);
	std::cout << "Please tell me your 'darkest Secret' :) ";
	std::getline(std::cin, tmp);
	this->contacts[idx].SetDarkestSecret(tmp);
}

void PhoneBook::Search()
{
	int inputIndex;
	std::string input;

	std::cout << "index     |first name|last name |nickname  |\n";
	for (int i = 0; i < this->contactSize; i++)
	{
		std::cout << std::setw(10) << i << "|";
		printTenLength(this->contacts[i].GetFirstName());
		printTenLength(this->contacts[i].GetLastName());
		printTenLength(this->contacts[i].GetNickName());
		std::cout << std::endl;
	}
	std::cout << "Please input index\n > ";
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << "\nbye\n";
		exit(0);
	}
	input.erase(0, input.find_first_not_of(" \t\n\v\f\r"));
	input.erase(input.find_last_not_of(" \t\n\v\f\r") + 1);
	if (!stringIsDigit(input))
	{
		std::cout << "Only numbers can be entered.\n";
		return ;
	}
	inputIndex = std::stoi(input);
	if (inputIndex >= 0 && inputIndex < this->contactSize)
	{
		std::cout << "------result------\n"
			<< "First Name: " << this->contacts[inputIndex].GetFirstName() << std::endl
			<< "Last Name: " << this->contacts[inputIndex].GetLastName() << std::endl
			<< "Nickname: " << this->contacts[inputIndex].GetNickName() << std::endl
			<< "Phone Number: " << this->contacts[inputIndex].GetPhoneNumber() << std::endl
			<< "Darkest Secret: " << this->contacts[inputIndex].GetDarkestSecret()
			<< "\n------------------\n";
	}
	else
	{
		std::cout << "The index could not be found.\n";
	}
}