/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:28:39 by sashin            #+#    #+#             */
/*   Updated: 2022/01/06 13:28:39 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contacts.hpp"

class PhoneBook
{
	private:
		Contacts contacts[8];
	public:
		PhoneBook();
		~PhoneBook();
		void Add();
		void Search();
		void Exit();
};

#endif
