/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:42:53 by sashin            #+#    #+#             */
/*   Updated: 2022/04/22 10:48:27 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class PresidentialPardonForm
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


	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& name, const int& signGrade, const int& executeGrade);
	PresidentialPardonForm(const PresidentialPardonForm& p);
	PresidentialPardonForm &operator=(const PresidentialPardonForm& p);
	~PresidentialPardonForm();
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& p);

#endif
