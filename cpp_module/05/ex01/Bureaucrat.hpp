/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 22:25:09 by sashin            #+#    #+#             */
/*   Updated: 2022/04/27 14:37:12 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>

class Form;

class Bureaucrat
{
public:
	static const int GRADE_MAX = 1;
	static const int GRADE_MIN = 150;

private:
	const std::string m_name;
	int m_grade;

	Bureaucrat(); // unused
	Bureaucrat &operator=(const Bureaucrat& b); // unused

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

	void signForm(Form& f);


	void incrementGrade();
	void decrementGrade();

	
	// Orthodox Canonical Form

	Bureaucrat(const std::string& name, const int& grade);
	Bureaucrat(const Bureaucrat& b);
	~Bureaucrat();

};

// ostream overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
