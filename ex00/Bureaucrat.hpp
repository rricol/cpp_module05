/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:01:05 by rricol            #+#    #+#             */
/*   Updated: 2023/01/13 17:55:00 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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

		std::string getName( void ) const;
		int getGrade( void ) const;
		void upGrade( int amount );
		void downGrade( int amount );

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{

				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					
				}
		}
	
};

std::ostream &operator<<( std::ostream &o, Bureaucrat const &inst);

#endif // BUREAUCRAT_HPP