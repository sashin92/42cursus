/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:38:10 by sashin            #+#    #+#             */
/*   Updated: 2022/04/28 20:27:38 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	Base* tmp = generate();
	std::cout << "---pointer---" << std::endl;
	identify(tmp);
	std::cout << "--reference--" << std::endl;
	identify(*tmp);
	delete tmp;

	return 0;
}
