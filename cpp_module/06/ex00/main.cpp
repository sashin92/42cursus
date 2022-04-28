/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:07:27 by sashin            #+#    #+#             */
/*   Updated: 2022/04/28 18:38:10 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
		return 1;

	Converter converter(argv[1]);
	if (converter.getEFlag())
		return 1;

	converter.printChar();
	converter.printInt();
	converter.printFloat();
	converter.printDouble();

	return 0;
}
