/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:43:45 by sashin            #+#    #+#             */
/*   Updated: 2022/04/27 18:37:27 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class RobotomyRequestForm: public Form
{
public:
	static const int RR_SIGN_GRADE = 72;
	static const int RR_EXEC_GRADE = 45;

private:
	RobotomyRequestForm(); // unused
	RobotomyRequestForm &operator=(const RobotomyRequestForm& src); // unused

public:
	virtual void execute(Bureaucrat const & executor) const;

	// Orthodox Canonical Form

	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& src);
	virtual ~RobotomyRequestForm();
};

#endif
