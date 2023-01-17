/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:01:05 by rricol            #+#    #+#             */
/*   Updated: 2023/01/17 10:35:13 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "_settings.h"

class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Bureaucrat
{
	private:
		std::string const	_name;
		int 				_grade;
		static int const 	maxGrade = 1;
		static int const 	minGrade = 150;

	public:
		Bureaucrat( void );
		Bureaucrat( std::string const name, int const grade );
		Bureaucrat( Bureaucrat const &rhs );
		~Bureaucrat( void );

		Bureaucrat	&operator=( Bureaucrat const &rhs );

		std::string	getName( void ) const;
		int			getGrade( void ) const;
		void		upGrade( int amount );
		void		downGrade( int amount );
		void		signForm( AForm &inst );
		void		executeForm( AForm const & form ) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<( std::ostream &os, Bureaucrat const &inst);
