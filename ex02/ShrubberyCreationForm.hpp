/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:28:02 by rricol            #+#    #+#             */
/*   Updated: 2023/01/15 17:16:11 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "A_Form.hpp"

class Bureaucrat;
class A_Form;
class RobotomyRequestForm;
class PresidentialPardonForm;

class ShrubberyCreationForm : public A_Form
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm const &rhs );
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=( ShrubberyCreationForm const &rhs );

		virtual void	executeAction( void ) const;
};

#endif // SHRUBBERYCREATIONFORM_HPP
