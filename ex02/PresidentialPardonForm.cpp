/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:38:27 by rricol            #+#    #+#             */
/*   Updated: 2023/01/15 17:09:11 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): 
A_Form::A_Form("Presidential Pardon Form", 145, 137), _target("Default target")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): 
A_Form::A_Form("Presidential Pardon Form", 145, 137), _target(target)
{
	std::cout << "PresidentialPardonForm overload constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &rhs ): A_Form::A_Form( rhs ), _target(rhs._target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( PresidentialPardonForm const &rhs )
{
	std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
	if (this != &rhs)
		this->_isSigned = rhs.getStatus();
	return *this;
}

void PresidentialPardonForm::executeAction( void ) const
{
	std::cout << this->_target << " a été pardonnée par Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<( std::ostream &o, PresidentialPardonForm const &rhs )
{
	o << rhs.getName() << " -> status : " << rhs.getStatus() << " | " << "Grade requis : Sign[" << rhs.getSignGrade() << "] - Exec[" << rhs.getExecGrade() << "]" << std::endl;
	return o;
}