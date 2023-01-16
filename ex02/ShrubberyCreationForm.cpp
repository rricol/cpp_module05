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

#include "_settings.h"

ShrubberyCreationForm::ShrubberyCreationForm(): 
AForm::AForm("Shrubbery Creation Form", 25, 5), _target("DefaultTarget")
{
	std::cout << LOG << "Shrubbery Creation Form default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): 
AForm::AForm("Shrubbery Creation Form", 25, 5), _target(target)
{
	std::cout << LOG << "Shrubbery Creation Form initialiser constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &rhs ): AForm::AForm( rhs ), _target(rhs._target)
{
	std::cout << LOG << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << LOG << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( ShrubberyCreationForm const &rhs )
{
	std::cout << LOG << "ShrubberyCreationForm assignment operator called" << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

std::string		ShrubberyCreationForm::getTarget( void ) const
{
	return this->_target;
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
	outfile.close();
   std::cout << INFO << "Fichier " << filename << " a été créé" << std::endl;
}

std::ostream &operator<<( std::ostream &os, ShrubberyCreationForm const &rhs )
{
	os << BOLD_P << "[ Formulaire ]" << RESET << std::endl;
	os << "‣ Name:\t\t" << rhs.getName() << std::endl;
	os << "‣ Status:\t" << rhs.getStatus() << std::endl;
	os << "‣ Target:\t" << rhs.getTarget() << std::endl;
	os << "‣ Grade sign:\t" << rhs.getSignGrade() << std::endl;
	os << "‣ Grade exec:\t" << rhs.getExecGrade() << "\n\n";
	return os;
}