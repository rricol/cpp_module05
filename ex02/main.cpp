/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:25:03 by rricol            #+#    #+#             */
/*   Updated: 2023/01/15 16:59:10 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main ( void )
{
	Bureaucrat a("Raph", 1);
	Bureaucrat b("Laurent", 15);
	Bureaucrat c("Lucas", 15);
	Bureaucrat d("Tito", 15);
	PresidentialPardonForm f1;
	RobotomyRequestForm f2;
	ShrubberyCreationForm f3;

	std::cout << std::endl << "Bienvenue à The Office!" << std::endl;
	std::cout << std::endl;
	std::cout << "Nous avons acutellement 3 employés :" << std::endl;
	std::cout << "> " << a;
	std::cout << "> " << b;
	std::cout << std::endl;
	std::cout << "Nous avons 3 Formulaires à disposition :" << std::endl;
	std::cout << "> " << f1;
	std::cout << "> " << f2;
	std::cout << "> " << f3;
	try
	{
		a.signForm(f1);
		std::cout << "> " << f1;
		f1.execute(a);
		// Bureaucrat tmp(b);
		// std::cout << std::endl;
		
		// std::cout << tmp.getName() << " tente de signer " << f1.getName() << " :" << std::endl;
		// tmp.signForm(f1);
		// std::cout << "> " << f1;
		
		// std::cout << std::endl;

		// std::cout << tmp.getName() << " tente à nouveau de signer " << f1.getName() << " :" << std::endl;
		// tmp.signForm(f1);
		// std::cout << "> " << f1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}