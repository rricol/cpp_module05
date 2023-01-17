/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:33:23 by rricol            #+#    #+#             */
/*   Updated: 2023/01/17 11:02:27 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "_settings.h"

class Intern
{
	private:
		// private attributs
	public:
		Intern( void );
		Intern( Intern const &rhs );
		~Intern( void );

		Intern &operator=( Intern const &rhs );

		AForm *makeForm( std::string name, std::string target );
		
		class FormDoesNotExist : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};	
};
