/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:33:23 by rricol            #+#    #+#             */
/*   Updated: 2023/01/17 11:06:05 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_settings.h"

Intern::Intern( void )
{
	std::cout << LOG << "Intern default constructor called";
}

Intern::Intern( Intern const &rhs )
{
	std::cout << LOG << "Intern copy constructor called";
	*this = rhs; 
}

Intern::~Intern( void )
{
	// std::cout << LOG << "Intern destructor called";
}

Intern &Intern::operator=( Intern const &rhs )
{
	if (this != &rhs)
		return *this;
	return *this;
}

AForm *Intern::makeForm( std::string name, std::string target )
{
	int formId = -1;
	AForm *newForm = NULL;
	std::string formList[3] = { "Presidential Pardon", "Robotomy Request", "Shrubbery Creation" }; 
	for (int i=0; i<3; i++)
	{
		if (name == formList[i])
			formId++;
	}
	switch (formId)
	{
	case 0:
		newForm = new PresidentialPardonForm(target);
		break;
	case 1:
		newForm = new RobotomyRequestForm(target);
		break;
	case 2:
		newForm = new ShrubberyCreationForm(target);
		break;
	default:
		std::cout << ERROR << "Création du formulaire " << name << " impossible" << std::endl;
		throw Intern::FormDoesNotExist();
		break;
	}
	std::cout << SUCCESS << "Intern a créé un formulaire " << newForm->getName() << std::endl;
	return (newForm);
}

const char *Intern::FormDoesNotExist::what() const throw()
{
	return (BOLD_RED "\nError → Requested Form does not exist\n" RESET);
}