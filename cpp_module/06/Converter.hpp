/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:07:17 by sashin            #+#    #+#             */
/*   Updated: 2022/04/27 22:11:12 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Converter.hpp */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>

class Converter
{
private:

protected:

public:


	Converter();
	Converter(const std::string& type);
	Converter(const Converter &src);
	Converter &operator=(const Converter &src);
	~Converter();
};

#endif
