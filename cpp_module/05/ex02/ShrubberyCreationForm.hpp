/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:43:49 by sashin            #+#    #+#             */
/*   Updated: 2022/04/22 12:19:41 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

# define SC_SIGN_GRADE 145
# define SC_EXEC_GRADE 137

class ShrubberyCreationForm: public Form
{
public:

	void execute(const Bureaucrat& b) const;

	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& s);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm& s);
	~ShrubberyCreationForm();
};


#endif
