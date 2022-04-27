/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:42:53 by sashin            #+#    #+#             */
/*   Updated: 2022/04/27 18:39:23 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class PresidentialPardonForm: public Form
{
public:
	static const int PP_SIGN_GRADE = 25;
	static const int PP_EXEC_GRADE = 5;

private:
	PresidentialPardonForm(); // unused
	PresidentialPardonForm &operator=(const PresidentialPardonForm& src); // unused

public:
	virtual void execute(Bureaucrat const & executor) const;

	// Orthodox Canonical Form

	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& src);
	virtual ~PresidentialPardonForm();
};

#endif
