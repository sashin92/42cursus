/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 22:25:11 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 22:25:11 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// class GradeTooHighException: public std::exception
const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade is Too High";
}

// class GradeTooLowException: public std::exception
const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade is Too Low";
}

void Bureaucrat::incrementGrade()
{
	--(this->m_grade);
	if (this->m_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	++(this->m_grade);
	if (this->m_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const std::string& Bureaucrat::getName() const
{
	return this->m_name;
}

const int& Bureaucrat::getGrade() const
{
	return this->m_grade;
}

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade)
: m_name(name), m_grade(grade)
{
	if (this->m_grade < GRADE_MAX)
		throw Bureaucrat::GradeTooLowException();
	else if (this->m_grade > GRADE_MIN)
		throw Bureaucrat::GradeTooHighException();
}


Bureaucrat::Bureaucrat(const Bureaucrat& b)
: m_name(b.getName()), m_grade(b.getGrade())
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& b)
{
	if (this != &b)
	{
		*const_cast<std::string*>(&this->m_name) = b.getName();
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	return (os << b.getName() << ",  Bureaucrat grade " << b.getGrade() << ".");
}
