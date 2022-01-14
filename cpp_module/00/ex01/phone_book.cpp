/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:26:26 by sashin            #+#    #+#             */
/*   Updated: 2022/01/06 13:26:26 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "phone_book.hpp"

PhoneBook::PhoneBook()
{
}


PhoneBook::~PhoneBook()
{
}

void PhoneBook::Add()
{
	std::string	tmp;

	std::cout << "First Name? ";
	std::cin >> tmp;
	this->contacts->SetFirstName(tmp);
	std::cout << "Last Name? ";
	std::cin >> tmp;
	this->contacts->SetLastName(tmp);
	std::cout << "Nick Name? ";
	std::cin >> tmp;
	this->contacts->SetNickName(tmp);
	std::cout << "Phone Number? ";
	std::cin >> tmp;
	this->contacts->SetPhoneNumber(tmp);
	std::cout << "Please tell me your 'darkest Secret' :)  ";
	std::cin >> tmp;
	this->contacts->SetDarkestSecret(tmp);
}

void PhoneBook::Search()
{
	std::cout << this->contacts->GetFirstName();
}