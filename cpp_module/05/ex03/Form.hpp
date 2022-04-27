/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:41:48 by sashin            #+#    #+#             */
/*   Updated: 2022/04/27 18:33:04 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
private:
	const std::string m_name;
	bool m_isSigned;
	const int m_signGrade;
	const int m_executeGrade;
	Form(); // unused
	Form &operator=(const Form& f); // unused

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

	virtual void execute(Bureaucrat const & executor) const=0;
	void beSigned(const Bureaucrat& b);

	void executableCheck(const Bureaucrat& b) const;


	// Orthodox Canonical Form

	Form(const std::string& name, const int& signGrade, const int& executeGrade);
	Form(const Form& f);
	virtual ~Form();
};

// ostream overload
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
