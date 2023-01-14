/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:38:27 by rricol            #+#    #+#             */
/*   Updated: 2023/01/14 16:50:31 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():
_name("Default Form"), _isSigned(false), _gradeSign(10), _gradeExec(1)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form( Form const &rhs ):
_name(rhs.getName()), _isSigned(rhs.getStatus()), _gradeSign(rhs.getSignGrade()), _gradeExec(rhs.getExecGrade())
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=( Form const &rhs )
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &rhs)
		this->_isSigned = rhs.getStatus();
	return *this;
}

std::string	Form::getName( void ) const
{
	return (this->_name);
}

bool Form::getStatus( void ) const
{
	return (this->_isSigned);
}

int	Form::getSignGrade( void ) const
{
	return (this->_gradeSign);
}

int Form::getExecGrade( void ) const
{
	return (this->_gradeExec);
}

void Form::beSigned( Bureaucrat const &inst )
{
	if ( this->_isSigned == true )
		std::cout << this->getName() << " est déjà signé." << std::endl;
	else if ( inst.getGrade() <= this->_gradeSign )
	{
		this->_isSigned = true;
		std::cout << inst.getName() << " a signé " << this->getName() << std::endl;
	}
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<( std::ostream &o, Form const &rhs )
{
	o << rhs.getName() << " -> status : " << rhs.getStatus() << " | " << "Grade requis : Sign[" << rhs.getSignGrade() << "] - Exec[" << rhs.getExecGrade() << "]" << std::endl;
	return o;
}