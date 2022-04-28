/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:07:17 by sashin            #+#    #+#             */
/*   Updated: 2022/04/28 20:34:58 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <exception>
# include <iostream>

class Data
{
private:
	std::string m_str;
	int m_int;
	double m_double;

	Data(const Data& src);
	Data &operator=(const Data& src);
public:
	std::string getStr() const;
	int getInt() const;
	double getDouble() const;

	Data();
	Data(std::string str, int i, double d);
	~Data();
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

void printPtr(uintptr_t raw);


std::ostream& operator<<(std::ostream& os, const Data& d);

#endif
