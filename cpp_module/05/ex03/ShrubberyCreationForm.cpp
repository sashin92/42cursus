/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:43:47 by sashin            #+#    #+#             */
/*   Updated: 2022/04/27 18:53:32 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const char* ShrubberyCreationForm::FileCannotMakeException::what(void) const throw()
{
	return "File cannot make";
}


void ShrubberyCreationForm::execute(const Bureaucrat& b) const
{
	std::fstream fs;
	std::string fileName = getName() + "_shrubbery";


	try
	{
		executableCheck(b);
		fs.open(fileName, std::ios_base::out);
		if (!fs.good())
		{
			throw (FileCannotMakeException());
		}
		std::cout << b.getName() << " executed " << getName() << std::endl;
		fs <<"\
             '.,\n\
              'b      *\n\
               '$    #.\n\
                $:   #:\n\
                *#  @):\n\
                :@,@):   ,.**:'\n\
    ,         :@@*: ..**'\n\
    '#o.    .:(@'.@*''\n\
        'bq,..:,@@*'   ,*\n\
        ,p$q8,:@)'  .p*'\n\
        '    '@@Pp@@*'\n\
              Y7'.'\n\
              :@):.\n\
             .:@:'.\n\
            .::(@:.  "
		<< std::endl;
		fs.close();
	}
	catch(std::exception& e)
	{
	std::cerr << b.getName() << " couldn't execute " << getName()
		<< " because " << e.what() << std::endl;
	}
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: Form(target, static_cast<const int>(SC_SIGN_GRADE), static_cast<const int>(SC_EXEC_GRADE))
{
	std::cout << "[ShrubberyCreationForm] constructor called." << std::endl;
}

// ShrubberyCreationForm::ShrubberyCreationForm() {} // unused
// ShrubberyCreationForm::ShrubberyCreationForm &operator=(const ShrubberyCreationForm& src) {} // unused

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
: Form(src)
{
	std::cout << "[ShrubberyCreationForm] copy constructor called." << std::endl;
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm] destructor called." << std::endl;
}
