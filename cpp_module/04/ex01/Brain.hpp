/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:00:49 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 19:00:49 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define IDEA_SIZE 100

class Brain
{
private:
	std::string m_idea[IDEA_SIZE];

public:

	void setIdea(const int& idx, std::string& idea);
	std::string getIdea(const int& idx) const;


	Brain();
	Brain(const Brain& brain);
	Brain &operator=(const Brain& brain);
	virtual ~Brain();
};

std::ostream& operator<<(std::ostream& os, const Brain& brain);

#endif
