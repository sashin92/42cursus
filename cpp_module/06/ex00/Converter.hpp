/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:07:17 by sashin            #+#    #+#             */
/*   Updated: 2022/04/28 18:40:11 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Converter.hpp */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <exception>
# include <iostream>

class Converter
{
private:
	const std::string m_input;
	double m_dValue;
	bool m_eFlag;

	Converter();
	Converter(const Converter& src);
	Converter &operator=(const Converter& src);

public:
	class InvalidInputException: public std::exception
	{
		const char* what() const throw();
	};

	const std::string getInput() const;
	bool getEFlag() const;

	void printChar();
	void printInt();
	void printFloat();
	void printDouble();

	Converter(const std::string& input);
	~Converter();
};

#endif
