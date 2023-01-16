/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:38:27 by rricol            #+#    #+#             */
/*   Updated: 2023/01/16 11:54:55 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_settings.h"

AForm::AForm( void ):
_name("Default Form"), _gradeSign(1), _gradeExec(1), _isSigned(false)
{
	std::cout << LOG << "AForm default constructor called" << std::endl;
}

AForm::AForm( std::string const &name, int const signGrade, int const execGrade):
_name(name), _gradeSign(signGrade), _gradeExec(execGrade), _isSigned(false)
{
	if (_gradeSign < 1 || _gradeExec < 1)
		throw GradeTooHighException();
	if (_gradeSign > 150 || _gradeExec > 150)
		throw GradeTooLowException();
	std::cout << LOG << "AForm initialiser constructor called" << std::endl;
}

AForm::AForm( AForm const &rhs ):
_name(rhs.getName()), _gradeSign(rhs.getSignGrade()), _gradeExec(rhs.getExecGrade()), _isSigned(rhs.getStatus())
{
	std::cout << LOG << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << LOG << "AForm destructor called" << std::endl;
}

AForm &AForm::operator=( AForm const &rhs )
{
	std::cout << LOG << "AForm assignment operator called" << std::endl;
	if (this != &rhs)
		this->_isSigned = rhs.getStatus();
	return *this;
}

std::string	AForm::getName( void ) const
{
	return (this->_name);
}

bool AForm::getStatus( void ) const
{
	return (this->_isSigned);
}

int	AForm::getSignGrade( void ) const
{
	return (this->_gradeSign);
}

int AForm::getExecGrade( void ) const
{
	return (this->_gradeExec);
}

bool AForm::beSigned( Bureaucrat const &inst )
{
	if ( this->_isSigned == true )
	{
		std::cout << WARNING << "Signature impossible: ";
		std::cout << this->getName() << " est déjà signé." << std::endl;
	}	
	else if ( inst.getGrade() <= this->_gradeSign )
	{
		this->_isSigned = true;
		std::cout << INFO << inst.getName() << " a signé " << this->getName() << std::endl;
		return (true);
	}
	else
	{
		throw AForm::GradeTooLowException();
	}
	return (false);
}

void AForm::execute(Bureaucrat const &executor) const
{
	if ( this->_isSigned == false )
		throw AForm::NotSignedException();
	else if ( executor.getGrade() <= this->_gradeExec )
		this->executeAction();
	else
	{
		std::cout << BOLD_RED << "Execution impossible:" << RESET << std::endl;
		throw AForm::GradeTooLowException();
	}
}

std::ostream &operator<<( std::ostream &os, AForm const &rhs )
{
	os << BOLD_P << "[ Formulaire ]" << RESET << std::endl;
	os << "‣ Name:\t\t" << rhs.getName() << std::endl;
	os << "‣ Status:\t" << rhs.getStatus() << std::endl;
	os << "‣ Grade sign:\t" << rhs.getSignGrade() << std::endl;
	os << "‣ Grade exec:\t" << rhs.getExecGrade() << "\n\n";
	return os;
}

// Exceptions

const char *AForm::GradeTooLowException::what() const throw()
{
	return (BOLD_RED "\n⊘ Error: Grade is too low\n" RESET);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return (BOLD_RED "\n⊘ Error: Grade is too high\n" RESET);
}

const char *AForm::NotSignedException::what() const throw()
{
	return (BOLD_RED "\n⊘ Error: Form is not signed\n" RESET);
}