/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:41:58 by sashin            #+#    #+#             */
/*   Updated: 2022/04/29 18:43:59 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"
# include <vector>

int main()
{
	std::vector<int> container;

	container.push_back(5);
	container.push_back(3);
	container.push_back(4);
	container.push_back(6);
	container.push_back(2);
	container.push_back(5);
	container.push_back(9);
	
	try
	{
		std::vector<int>::iterator iter = easyfind(container, 4);
		std::cout << "this is: " << *iter << std::endl;
		++iter;
		std::cout << "this is: " << *iter << std::endl;
		iter = easyfind(container, 11);
		std::cout << "this is: " << *iter << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
