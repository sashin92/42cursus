/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:07:27 by sashin            #+#    #+#             */
/*   Updated: 2022/04/28 19:32:42 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main(void)
{
	Data data;
	uintptr_t numPtr = serialize(&data);

	std::cout << data << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "data is serialized like this: " << numPtr << std::endl;
	printPtr(numPtr);
	std::cout << "--------------------" << std::endl;


	return 0;
}
