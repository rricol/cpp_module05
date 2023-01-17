/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:38:27 by rricol            #+#    #+#             */
/*   Updated: 2023/01/16 15:55:41 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_settings.h"

RobotomyRequestForm::RobotomyRequestForm(): 
AForm::AForm("Robotomy Request Form", 72, 45), _target("Default target")
{
	std::cout << LOG << "Robotomy Request Form default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): 
AForm::AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << LOG << "Robotomy Request Form initialiser constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &rhs ): AForm::AForm( rhs ), _target(rhs._target)
{
	std::cout << LOG << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << LOG << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( RobotomyRequestForm const &rhs )
{
	std::cout << LOG << "RobotomyRequestForm assignment operator called" << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

std::string		RobotomyRequestForm::getTarget( void ) const
{
	return this->_target;
}

void RobotomyRequestForm::executeAction( void ) const
{
	std::cout << INFO << "Brrzzzzzzzzz bip bip ... ";
	std::cout << this->getTarget() << " a été robotomisé." << std::endl;
}

std::ostream &operator<<( std::ostream &os, RobotomyRequestForm const &rhs )
{
	os << BOLD_P << "[ Formulaire ]" << RESET << std::endl;
	os << "‣ Name:\t\t" << rhs.getName() << std::endl;
	os << "‣ Status:\t" << rhs.getStatus() << std::endl;
	os << "‣ Target:\t" << rhs.getTarget() << std::endl;
	os << "‣ Grade sign:\t" << rhs.getSignGrade() << std::endl;
	os << "‣ Grade exec:\t" << rhs.getExecGrade() << "\n\n";
	return os;
}