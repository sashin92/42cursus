/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:41:42 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 23:41:42 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* Form::GradeTooHighException::what(void) const throw()
{
	return "Form Grade is Too High.";
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return "Form Grade is Too Low.";
}

const std::string& Form::getName() const
{
	return m_name;
}

const bool& Form::getIsSigned() const
{
	return m_isSigned;
}

const int& Form::getSignGrade() const
{
	return m_signGrade;
}

const int& Form::getExecuteGrade() const
{
	return m_executeGrade;
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= m_signGrade)
	{
		m_isSigned = true;
	}
	else
	{
		throw Form::GradeTooHighException();
	}
}

Form::Form()
: m_signGrade(0), m_executeGrade(0) {}

Form::Form(const std::string& name, const int& signGrade, const int& executeGrade)
: m_name(name), m_signGrade(signGrade), m_executeGrade(executeGrade)
{
	if (m_signGrade < GRADE_MAX || m_executeGrade < GRADE_MAX)
		throw Form::GradeTooHighException();
	else if (m_signGrade > GRADE_MIN || m_executeGrade > GRADE_MIN)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& f)
: m_name(f.getName()), m_isSigned(f.getIsSigned()), m_signGrade(f.getSignGrade()), m_executeGrade(f.getExecuteGrade())
{
	if (m_signGrade < GRADE_MAX || m_executeGrade < GRADE_MAX)
		throw Form::GradeTooHighException();
	else if (m_signGrade > GRADE_MIN || m_executeGrade > GRADE_MIN)
		throw Form::GradeTooLowException();
}

Form &Form::operator=(const Form& f)
{
	if (this != &f)
	{
		*(const_cast<std::string* >(&m_name)) = f.getName();
		*(const_cast<int* >(&m_signGrade)) = f.getSignGrade();
		*(const_cast<int* >(&m_executeGrade)) = f.getExecuteGrade();
		m_isSigned = f.getIsSigned();
	}
	return *this;
}

Form::~Form(){}


std::ostream& operator<<(std::ostream& os, const Form& f)
{
	return os
	<< "form name: " << f.getName()
	<< "  execute grade: " << f.getExecuteGrade()
	<< "   sign grade: "<< f.getSignGrade();
}
