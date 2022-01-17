/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:44:17 by sashin            #+#    #+#             */
/*   Updated: 2022/01/06 13:44:17 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <iostream>

class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
public:
	Contact();
	~Contact();
	std::string	GetFirstName();
	std::string	GetLastName();
	std::string	GetNickName();
	std::string	GetPhoneNumber();
	std::string	GetDarkestSecret();
	void		SetFirstName(std::string firstName);
	void		SetLastName(std::string lastName);
	void		SetNickName(std::string nickName);
	void		SetPhoneNumber(std::string phoneNumber);
	void		SetDarkestSecret(std::string darkestSecret);

};

#endif
