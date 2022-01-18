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
#include "Zombie.hpp"

int main(void)
{
	Zombie *heapZombie;

	heapZombie = Zombie::zombieHorde(ZOMBIE_SIZE, "citizen");
	for(int i = 0; i < ZOMBIE_SIZE; i++)
	{
		std::cout << i + 1 << " ";
		heapZombie[i].announce();
	}
	delete[] heapZombie;
	return 0;
}
