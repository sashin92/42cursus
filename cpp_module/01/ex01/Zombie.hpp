/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:34:29 by sashin            #+#    #+#             */
/*   Updated: 2022/01/18 11:34:29 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# define ZOMBIE_SIZE 5

class Zombie
{
private:
	std::string name;
public:
	Zombie( std::string name );
	Zombie();
	~Zombie();
	void announce( void ) const;

	static Zombie* zombieHorde( int N, std::string name );
};


#endif
