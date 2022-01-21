/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:32:25 by sashin            #+#    #+#             */
/*   Updated: 2022/01/18 11:32:25 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Karen.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "usage: ./karenFilter \"LEVEL\"\n"
				<< "[LEVEL: DEBUG, INFO, WARNING, ERROR]\n";
		return 1;
	}
	Karen karen;
	std::string level = argv[1];
	karen.complain(level);
	return 0;
}
