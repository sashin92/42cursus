/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:43:47 by sashin            #+#    #+#             */
/*   Updated: 2022/04/23 12:54:04 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <sstream>
#include <string>


// void ShrubberyCreationForm::execute(const Bureaucrat& b) const
// {
// 	std::fstream fs;
// 	std::ostringstream oss;
// 	std::string fileStr;

// 	fileStr = target + "_shrubbery";

// 	fs.open

// 	<target>_shrubbery
// }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: Form(target, SC_SIGN_GRADE, SC_EXEC_GRADE)
{	
}

ShrubberyCreationForm::ShrubberyCreationForm()
: Form()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s)
: Form(s)
{
}

ShrubberyCreationForm::ShrubberyCreationForm &operator=(const ShrubberyCreationForm& s)
{
	Form::


}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
