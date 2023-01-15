/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Form.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:28:02 by rricol            #+#    #+#             */
/*   Updated: 2023/01/15 17:15:24 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_Form_HPP
#define A_Form_HPP

#include "Bureaucrat.hpp"
#include <fstream> 

class Bureaucrat;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class A_Form
{
	protected:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeSign;
		const int			_gradeExec;
	public:
		A_Form();
		A_Form( std::string name, int signGrade, int execGrade);
		A_Form( A_Form const &rhs );
		virtual ~A_Form();

		A_Form &operator=( A_Form const &rhs );
		
		std::string		getName( void ) const;
		bool 			getStatus( void ) const;
		int				getSignGrade( void ) const;
		int 			getExecGrade( void ) const;
		void 			beSigned( Bureaucrat const &inst );
		void			execute(Bureaucrat const & executor) const;
		virtual void	executeAction( void ) const = 0;
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("[exception] Grade is too high.");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("[exception] Grade is too low.");
				}
		};
		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("[exception] Form is not signed.");
				}
		};
};

std::ostream &operator<<( std::ostream &o, A_Form const &inst);

#endif // A_Form_HPP
