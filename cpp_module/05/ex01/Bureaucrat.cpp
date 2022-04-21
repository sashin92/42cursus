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
#include "Form.hpp"
#include <exception>

// class GradeTooHighException: public std::exception
const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Bureaucrat Grade is Too High";
}

// class GradeTooLowException: public std::exception
const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Bureaucrat Grade is Too Low";
}

void Bureaucrat::incrementGrade()
{
	--(this->m_grade);
	if (this->m_grade < GRADE_MAX)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	++(this->m_grade);
	if (this->m_grade > GRADE_MIN)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(const Form& f) const
{
	try
	{
		(*const_cast<Form*>(&f)).beSigned(*this);
		std::cout << m_name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << m_name << " couldn't sign " << f.getName()
		<< " because " << e.what() << std::endl;
	}
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
	if (this->m_grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else if (this->m_grade > 150)
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
