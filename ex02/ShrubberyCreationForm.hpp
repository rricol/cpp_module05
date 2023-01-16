/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:28:02 by rricol            #+#    #+#             */
/*   Updated: 2023/01/16 15:21:56 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "_settings.h"

class Bureaucrat;
class AForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm const &rhs );
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=( ShrubberyCreationForm const &rhs );

		std::string		getTarget( void ) const;
		virtual void	executeAction( void ) const;
};

std::ostream &operator<<( std::ostream &os, ShrubberyCreationForm const &rhs );

#endif // SHRUBBERYCREATIONFORM_HPP
