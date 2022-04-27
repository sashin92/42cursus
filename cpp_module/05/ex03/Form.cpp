/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:41:42 by sashin            #+#    #+#             */
/*   Updated: 2022/04/27 20:35:43 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

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
		throw Bureaucrat::GradeTooLowException();
	}
}

void Form::executableCheck(const Bureaucrat& b) const
{
	if (b.getGrade() > m_executeGrade)
		throw Bureaucrat::GradeTooLowException();
}


// Orthodox Canonical Form

// Form::Form(): m_signGrade(0), m_executeGrade(0) {} // unused
// Form &Form::operator=(const Form& f) {} // unused

Form::Form(const std::string& name, const int& signGrade, const int& executeGrade)
: m_name(name),
	m_signGrade(signGrade),
	m_executeGrade(executeGrade)
{
	std::cout << "[Form] constructor called." << std::endl;
	if (m_signGrade < Bureaucrat::GRADE_MAX || m_executeGrade < Bureaucrat::GRADE_MAX)
		throw Form::GradeTooHighException();
	else if (m_signGrade > Bureaucrat::GRADE_MIN || m_executeGrade > Bureaucrat::GRADE_MIN)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& f)
: m_name(f.m_name),
	m_isSigned(f.m_isSigned),
	m_signGrade(f.m_signGrade),
	m_executeGrade(f.m_executeGrade)
{
	std::cout << "[Form] copy constructor called." << std::endl;
	if (m_signGrade < Bureaucrat::GRADE_MAX || m_executeGrade < Bureaucrat::GRADE_MAX)
		throw Form::GradeTooHighException();
	else if (m_signGrade > Bureaucrat::GRADE_MIN || m_executeGrade > Bureaucrat::GRADE_MIN)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
	std::cout << "[Form] destructor called." << std::endl;
}

// ostream overload
std::ostream& operator<<(std::ostream& os, const Form& f)
{
	return os
	<< "Target: [" << f.getName()
	<< "], isSigned?: [" << f.getIsSigned()
	<< "], Execute Grade: [" << f.getExecuteGrade()
	<< "], Sign Grade: ["<< f.getSignGrade() << "]";
}
