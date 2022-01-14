/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:44:19 by sashin            #+#    #+#             */
/*   Updated: 2022/01/06 13:44:19 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "contacts.hpp"

Contacts::Contacts()
{
}


Contacts::~Contacts()
{
}

std::string	Contacts::GetFirstName()
{
	return (this->firstName);
}

std::string	Contacts::GetLastName()
{
	return (this->lastName);
}

std::string	Contacts::GetNickName()
{
	return (this->nickName);
}

std::string	Contacts::GetPhoneNumber()
{
	return (this->phoneNumber);
}

std::string	Contacts::GetDarkestSecret()
{
	return (this->darkestSecret);
}

void		Contacts::SetFirstName(std::string firstName)
{
	this->firstName = firstName;
}

void		Contacts::SetLastName(std::string lastName)
{
	this->lastName = lastName;
}

void		Contacts::SetNickName(std::string nickName)
{
	this->nickName = nickName;
}

void		Contacts::SetPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void		Contacts::SetDarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}
