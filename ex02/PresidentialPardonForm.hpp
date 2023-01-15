/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:28:02 by rricol            #+#    #+#             */
/*   Updated: 2023/01/15 17:15:54 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "A_Form.hpp"

class Bureaucrat;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class A_Form;

class PresidentialPardonForm : public A_Form
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( PresidentialPardonForm const &rhs );
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm &operator=( PresidentialPardonForm const &rhs );
		
		virtual void	executeAction( void ) const;
};

#endif // PRESIDENTIALPARDONFORM_HPP