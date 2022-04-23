/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:43:45 by sashin            #+#    #+#             */
/*   Updated: 2022/04/22 10:46:37 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class RobotomyRequestForm
{
private:
	const std::string m_name;
	bool m_isSigned;
	const int m_signGrade;
	const int m_executeGrade;

public:
	class GradeTooHighException: public std::exception
	{
	public:
	  const char* what(void) const throw();
	};

	class GradeTooLowException: public std::exception
	{
	public:
	  const char* what(void) const throw();
	};

	const std::string& getName() const;
	const bool& getIsSigned() const;
	const int& getSignGrade() const;
	const int& getExecuteGrade() const;

	void beSigned(const Bureaucrat& b);


	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& name, const int& signGrade, const int& executeGrade);
	RobotomyRequestForm(const RobotomyRequestForm& r);
	RobotomyRequestForm &operator=(const RobotomyRequestForm& r);
	~RobotomyRequestForm();
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& r);

#endif
