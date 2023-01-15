/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Form.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:38:27 by rricol            #+#    #+#             */
/*   Updated: 2023/01/15 16:57:19 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Form.hpp"

A_Form::A_Form():
_name("Default A_Form"), _isSigned(false), _gradeSign(10), _gradeExec(1)
{
	std::cout << "A_Form default constructor called" << std::endl;
}

A_Form::A_Form( std::string name, int signGrade, int execGrade):
_name(name), _isSigned(false), _gradeSign(signGrade), _gradeExec(execGrade)
{
	std::cout << "A_Form default constructor called" << std::endl;
}

A_Form::A_Form( A_Form const &rhs ):
_name(rhs.getName()), _isSigned(rhs.getStatus()), _gradeSign(rhs.getSignGrade()), _gradeExec(rhs.getExecGrade())
{
	std::cout << "A_Form copy constructor called" << std::endl;
}

A_Form::~A_Form()
{
	std::cout << "A_Form destructor called" << std::endl;
}

A_Form &A_Form::operator=( A_Form const &rhs )
{
	std::cout << "A_Form assignment operator called" << std::endl;
	if (this != &rhs)
		this->_isSigned = rhs.getStatus();
	return *this;
}

std::string	A_Form::getName( void ) const
{
	return (this->_name);
}

bool A_Form::getStatus( void ) const
{
	return (this->_isSigned);
}

int	A_Form::getSignGrade( void ) const
{
	return (this->_gradeSign);
}

int A_Form::getExecGrade( void ) const
{
	return (this->_gradeExec);
}

void A_Form::beSigned( Bureaucrat const &inst )
{
	if ( this->_isSigned == true )
		std::cout << this->getName() << " est déjà signé." << std::endl;
	else if ( inst.getGrade() <= this->_gradeSign )
	{
		this->_isSigned = true;
		std::cout << inst.getName() << " a signé " << this->getName() << std::endl;
	}
	else
	{
		std::cout << "Signature impossible:" << std::endl;
		throw A_Form::GradeTooLowException();
	}
}

void A_Form::execute(Bureaucrat const & executor) const
{
	if ( this->_isSigned == false )
		throw A_Form::NotSignedException();
	else if ( executor.getGrade() <= this->_gradeExec )
	{
		this->executeAction();
	}
	else
	{
		std::cout << "Execution impossible:" << std::endl;
		throw A_Form::GradeTooLowException();
	}
}

std::ostream &operator<<( std::ostream &o, A_Form const &rhs )
{
	o << rhs.getName() << " -> status : " << rhs.getStatus() << " | " << "Grade requis : Sign[" << rhs.getSignGrade() << "] - Exec[" << rhs.getExecGrade() << "]" << std::endl;
	return o;
}