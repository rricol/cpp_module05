/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:01:05 by rricol            #+#    #+#             */
/*   Updated: 2023/01/15 17:15:20 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "A_Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class A_Form;

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
		static int const maxGrade = 1;
		static int const minGrade = 150;

	public:
		Bureaucrat();
		Bureaucrat( std::string name, int grade );
		Bureaucrat( Bureaucrat const &rhs );
		~Bureaucrat();

		Bureaucrat &operator=( Bureaucrat const &rhs );

		std::string	getName( void ) const;
		int			getGrade( void ) const;
		void		upGrade( int amount );
		void		downGrade( int amount );
		void		signForm( A_Form &inst );
		void		signForm( PresidentialPardonForm &inst );
		void		executeForm( A_Form const & form );

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("[exception] Upgrade impossible: Grade is too high.");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("[exception] Upgrade impossible: Grade is too low.");
				}
		};
};

std::ostream &operator<<( std::ostream &o, Bureaucrat const &inst);

#endif // BUREAUCRAT_HPP