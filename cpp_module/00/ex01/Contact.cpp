/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:44:19 by sashin            #+#    #+#             */
/*   Updated: 2022/01/06 13:44:19 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact()
{
}


Contact::~Contact()
{
}

std::string	Contact::GetFirstName()
{
	return (this->firstName);
}

std::string	Contact::GetLastName()
{
	return (this->lastName);
}

std::string	Contact::GetNickName()
{
	return (this->nickName);
}

std::string	Contact::GetPhoneNumber()
{
	return (this->phoneNumber);
}

std::string	Contact::GetDarkestSecret()
{
	return (this->darkestSecret);
}

void		Contact::SetFirstName(std::string firstName)
{
	this->firstName = firstName;
}

void		Contact::SetLastName(std::string lastName)
{
	this->lastName = lastName;
}

void		Contact::SetNickName(std::string nickName)
{
	this->nickName = nickName;
}

void		Contact::SetPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void		Contact::SetDarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}
