/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:28:02 by rricol            #+#    #+#             */
/*   Updated: 2023/01/16 11:54:40 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "_settings.h"

class Bureaucrat;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class AForm
{
	private:
		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExec;
		bool				_isSigned;
	
	public:
		AForm();
		AForm( std::string const &name, int const signGrade, int const execGrade);
		AForm( AForm const &rhs );
		virtual ~AForm();

		AForm &operator=( AForm const &rhs );
		
		// Getter
		std::string		getName( void ) const;
		bool 			getStatus( void ) const;
		int				getSignGrade( void ) const;
		int 			getExecGrade( void ) const;
		
		// Methods
		bool 			beSigned( Bureaucrat const &inst );
		void			execute(Bureaucrat const &executor) const;
		virtual void	executeAction( void ) const = 0;
		
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
		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<( std::ostream &os, AForm const &inst);
