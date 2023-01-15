/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:38:27 by rricol            #+#    #+#             */
/*   Updated: 2023/01/15 16:01:46 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): 
A_Form::A_Form("Robotomy Request Form", 72, 45), _target("Default target")
{
	std::cout << "Robotomy Request Form default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): 
A_Form::A_Form("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << "Robotomy Request Form overload constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &rhs ): A_Form::A_Form( rhs ), _target(rhs._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( RobotomyRequestForm const &rhs )
{
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	if (this != &rhs)
		this->_isSigned = rhs.getStatus();
	return *this;
}

void RobotomyRequestForm::executeAction( void ) const
{
	std::cout << "Brrzzzzzzzzz bip bip" << std::endl;
	std::cout << this->getName() << " a été robotomisé." << std::endl;
}

std::ostream &operator<<( std::ostream &o, RobotomyRequestForm const &rhs )
{
	o << rhs.getName() << " -> status : " << rhs.getStatus() << " | " << "Grade requis : Sign[" << rhs.getSignGrade() << "] - Exec[" << rhs.getExecGrade() << "]" << std::endl;
	return o;
}