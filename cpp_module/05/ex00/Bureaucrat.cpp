/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 22:25:11 by sashin            #+#    #+#             */
/*   Updated: 2022/04/27 14:37:44 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade is Too High";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade is Too Low";
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
	*this = src;
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
