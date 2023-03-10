/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:35:45 by rricol            #+#    #+#             */
/*   Updated: 2023/01/16 15:40:07 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_settings.h"

// Construcors & Destructors

Bureaucrat::Bureaucrat( void ):
_name("Bureaucrat Lambda"), _grade(150)
{
	std::cout << LOG << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( std::string const name, int const grade ):
_name(name), _grade(grade)
{
	if (_grade > minGrade)
		throw GradeTooLowException();
	if (_grade < maxGrade)
		throw GradeTooHighException();
	std::cout << LOG << "Bureaucrat overload constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const &rhs ):
_name(rhs.getName())
{
	std::cout << LOG << "Bureaucrat copy constructor called" << std::endl;
	*this = rhs;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << LOG << "Bureaucrat destructor called" << std::endl;
}

// Methods

std::string Bureaucrat::getName( void ) const
{
	return this->_name;
}

int Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}

void Bureaucrat::upGrade( int amount )
{
	if (this->_grade == this->maxGrade || (this->_grade - amount) < this->maxGrade)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= amount;
}

void Bureaucrat::downGrade( int amount )
{
	if (this->_grade == this->minGrade || (this->_grade + amount) > this->minGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += amount;
}

void Bureaucrat::signForm( AForm &inst )
{
	if (this->getGrade() > inst.getSignGrade() || inst.getStatus() == true)
		std::cout << ERROR << this->getName() << " n'a pas pu sign?? " << inst.getName() << std::endl;
	inst.beSigned( *this );
}

void Bureaucrat::executeForm( AForm const & form ) const
{
	std::cout << SUCCESS << this->getName() << " a execut?? " << form.getName() << std::endl;
	form.execute(*this);
}

// Operator overloads

Bureaucrat &Bureaucrat::operator=( Bureaucrat const &rhs )
{
	std::cout << LOG << "Bureaucrat assignment operator called" << std::endl;
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return *this;
}

std::ostream &operator<<( std::ostream &os, Bureaucrat const &rhs )
{
	os << BOLD_P << "[ Bureaucrat ]" << RESET << std::endl;
	os << "??? Name:\t\t" << rhs.getName() << std::endl;
	os << "??? Grade:\t" << rhs.getGrade() << "\n\n";
	return os;
}

// Exceptions

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return (BOLD_RED "\n??? Error: Grade is too low\n" RESET);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return (BOLD_RED "\n??? Error: Grade is too high\n" RESET);
}
