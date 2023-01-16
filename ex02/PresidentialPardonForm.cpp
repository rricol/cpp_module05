/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:38:27 by rricol            #+#    #+#             */
/*   Updated: 2023/01/16 15:28:12 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_settings.h"

PresidentialPardonForm::PresidentialPardonForm(): 
AForm::AForm("Presidential Pardon Form", 145, 137), _target("Default target")
{
	std::cout << LOG << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ): 
AForm::AForm("Presidential Pardon Form", 145, 137), _target(target)
{
	std::cout << LOG << "PresidentialPardonForm overload constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &rhs ):
AForm::AForm( rhs ), _target(rhs._target)
{
	std::cout << LOG << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << LOG << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( PresidentialPardonForm const &rhs )
{
	std::cout << LOG << "PresidentialPardonForm assignment operator called" << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

std::string		PresidentialPardonForm::getTarget( void ) const
{
	return this->_target;
}

void PresidentialPardonForm::executeAction( void ) const
{
	std::cout << INFO << this->_target << " a été pardonnée par Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<( std::ostream &os, PresidentialPardonForm const &rhs )
{
	os << BOLD_P << "[ Formulaire ]" << RESET << std::endl;
	os << "‣ Name:\t\t" << rhs.getName() << std::endl;
	os << "‣ Status:\t" << rhs.getStatus() << std::endl;
	os << "‣ Target:\t" << rhs.getTarget() << std::endl;
	os << "‣ Grade sign:\t" << rhs.getSignGrade() << std::endl;
	os << "‣ Grade exec:\t" << rhs.getExecGrade() << "\n\n";
	return os;
}