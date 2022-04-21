/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 22:25:09 by sashin            #+#    #+#             */
/*   Updated: 2022/04/21 22:25:09 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

# define GRADE_MAX 1
# define GRADE_MIN 150

class Form;

class Bureaucrat
{
private:
	const std::string m_name;
	int m_grade;

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
	const int& getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(const Form& f) const;

	Bureaucrat();
	Bureaucrat(const std::string& name, const int& grade);
	Bureaucrat(const Bureaucrat& b);
	Bureaucrat &operator=(const Bureaucrat& b);
	~Bureaucrat();

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
