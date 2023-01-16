/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:28:02 by rricol            #+#    #+#             */
/*   Updated: 2023/01/16 15:15:00 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "_settings.h"

class Bureaucrat;
class ShrubberyCreationForm;
class AForm;
class PresidentialPardonForm;

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( RobotomyRequestForm const &rhs );
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm &operator=( RobotomyRequestForm const &rhs );
		
		std::string		getTarget( void ) const;
		virtual void 	executeAction( void ) const;
};

std::ostream &operator<<( std::ostream &os, RobotomyRequestForm const &rhs );

#endif // ROBOTOMYREQUESTFORM_HPP