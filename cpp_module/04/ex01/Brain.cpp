/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:00:47 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 19:00:47 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

void Brain::setIdea(const int& idx, std::string& idea)
{
	this->m_idea[idx] = idea;
}

std::string Brain::getIdea(const int& idx) const
{
	return this->m_idea[idx];
}

Brain::Brain()
{
	std::cout << "Brain default constructor executed." << std::endl;
	for (int i = 0; i < IDEA_SIZE; i++)
	{
		this->m_idea[i] = "i'm thinking in think...";
	}
}

Brain::Brain(const Brain& brain)
{
	std::cout << "Brain copy constructor executed." << std::endl;
	*this = brain;
}

Brain &Brain::operator=(const Brain& brain)
{
	std::cout << "Brain assignment operator overload executed." << std::endl;
	if (this != &brain)
	{
		for (int i = 0; i < IDEA_SIZE; i++)
			this->m_idea[i] = brain.getIdea(i);
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor executed." << std::endl;

}

std::ostream& operator<<(std::ostream& os, const Brain& brain)
{
	for (int i = 0; i < IDEA_SIZE; ++i)
		std::cout << i + 1 << ": " << brain.getIdea(i) << std::endl;
	return os;
}
