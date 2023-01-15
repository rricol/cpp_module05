/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:38:27 by rricol            #+#    #+#             */
/*   Updated: 2023/01/15 14:05:04 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): 
A_Form::A_Form("Shrubbery Creation Form", 25, 5), _target("Default target")
{
	std::cout << "Shrubbery Creation Form default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): 
A_Form::A_Form("Shrubbery Creation Form", 25, 5), _target(target)
{
	std::cout << "Shrubbery Creation Form overload constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &rhs ): A_Form::A_Form( rhs ), _target(rhs._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( ShrubberyCreationForm const &rhs )
{
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	if (this != &rhs)
		this->_isSigned = rhs.getStatus();
	return *this;
}

void ShrubberyCreationForm::executeAction( void ) const
{
	std::string filename = this->_target + "_shrubbery";
	std::ofstream outfile (filename);
	outfile <<"\
					.o00o \n\
                   o000000oo \n\
                  00000000000o \n\
                 00000000000000 \n\
              oooooo  00000000  o88o \n\
           ooOOOOOOOoo  ```''  888888 \n\
         OOOOOOOOOOOO'.qQQQQq. `8888' \n\
        oOOOOOOOOOO'.QQQQQQQQQQ/.88' \n\
        OOOOOOOOOO'.QQQQQQQQQQ/ /q \n\
         OOOOOOOOO QQQQQQQQQQ/ /QQ \n\
           OOOOOOOOO `QQQQQQ/ /QQ' \n\
             OO:F_P:O `QQQ/  /Q' \n\
                \\\\. \\ |  // | \n\
                d\\ \\\\\\|_//// \n\
                qP| \\ _' `|Ob \n\
                   \\  / \\  \\Op \n\
                   |  | O| | \n\
           _       /\\. \\_/ /\\ \n\
            `---__/|_\\   //|  __ \n\
                  `-'  `-'`-'-'";
	std::cout << std::endl;
	outfile.close();
}

std::ostream &operator<<( std::ostream &o, ShrubberyCreationForm const &rhs )
{
	o << rhs.getName() << " -> status : " << rhs.getStatus() << " | " << "Grade requis : Sign[" << rhs.getSignGrade() << "] - Exec[" << rhs.getExecGrade() << "]" << std::endl;
	return o;
}