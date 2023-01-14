/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:28:02 by rricol            #+#    #+#             */
/*   Updated: 2023/01/14 16:48:52 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeSign;
		const int			_gradeExec;
	public:
		Form();
		Form( Form const &rhs );
		~Form();

		Form &operator=( Form const &rhs );
		
		std::string	getName( void ) const;
		bool getStatus( void ) const;
		int	getSignGrade( void ) const;
		int getExecGrade( void ) const;
		void beSigned( Bureaucrat const &inst );
		
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
};

std::ostream &operator<<( std::ostream &o, Form const &inst);

#endif // FORM_HPP
