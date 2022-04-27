/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:43:49 by sashin            #+#    #+#             */
/*   Updated: 2022/04/27 18:37:58 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <exception>
# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class ShrubberyCreationForm: public Form
{
public:
	static const int SC_SIGN_GRADE = 145;
	static const int SC_EXEC_GRADE = 137;

private:
	ShrubberyCreationForm(); // unused
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm& src); // unused

public:
	class FileCannotMakeException: public std::exception
	{
	public:
	  const char* what(void) const throw();
	};

	virtual void execute(Bureaucrat const & executor) const;

	// Orthodox Canonical Form

	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& src);
	virtual ~ShrubberyCreationForm();
};


#endif
