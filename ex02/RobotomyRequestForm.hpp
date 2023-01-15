/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:28:02 by rricol            #+#    #+#             */
/*   Updated: 2023/01/15 17:16:03 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "A_Form.hpp"

class Bureaucrat;
class ShrubberyCreationForm;
class A_Form;
class PresidentialPardonForm;

class RobotomyRequestForm : public A_Form
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( RobotomyRequestForm const &rhs );
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm &operator=( RobotomyRequestForm const &rhs );
		
		virtual void executeAction( void ) const;
};

#endif // ROBOTOMYREQUESTFORM_HPP