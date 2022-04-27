/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 22:25:11 by sashin            #+#    #+#             */
/*   Updated: 2022/04/27 17:01:02 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Bureaucrat Grade is Too High";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Bureaucrat Grade is Too Low";
}

void Bureaucrat::incrementGrade()
{
	if (this->m_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	--(this->m_grade);
}

void Bureaucrat::decrementGrade()
{
	if (this->m_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	++(this->m_grade);
}

const std::string& Bureaucrat::getName() const
{
	return this->m_name;
}

const int& Bureaucrat::getGrade() const
{
	return this->m_grade;
}

void Bureaucrat::signForm(Form& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << m_name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << m_name << " couldn't sign " << f.getName()
		<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const Form& form)
{
	try
	{
		form.execute(*this);
		std::cout << m_name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "[ERROR] "<< m_name << " cannot execute " << form.getName() << ": " << e.what() << std::endl;
	}
}


// Orthodox Canonical Form

// Bureaucrat::Bureaucrat() { std::cout << "[] constructor called. (default)" << std::endl; } // unused
// Bureaucrat &Bureaucrat::operator=(const Bureaucrat& src) { std::cout << "[] copy assignment operator called. (default)" << std::endl; } // unused


Bureaucrat::Bureaucrat(const std::string& name, const int& grade)
: m_name(name), m_grade(grade)
{
	std::cout << "[Bureaucrat] constructor called." << std::endl;
	if (this->m_grade < GRADE_MAX)
		throw Bureaucrat::GradeTooLowException();
	else if (this->m_grade > GRADE_MIN)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
: m_name(src.m_name), m_grade(src.m_grade)
{
	std::cout << "[Bureaucrat] copy constructor called." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat] destructor called." << std::endl;
}

// ostream overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	return (os << b.getName() << ",  Bureaucrat grade " << b.getGrade() << ".");
}
