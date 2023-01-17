/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:28:02 by rricol            #+#    #+#             */
/*   Updated: 2023/01/17 10:35:29 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "_settings.h"

class Bureaucrat;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class AForm;

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( PresidentialPardonForm const &rhs );
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm &operator=( PresidentialPardonForm const &rhs );
		
		std::string		getTarget( void ) const;
		virtual void	executeAction( void ) const;
};

std::ostream &operator<<( std::ostream &os, PresidentialPardonForm const &rhs );
