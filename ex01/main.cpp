/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:25:03 by rricol            #+#    #+#             */
/*   Updated: 2023/01/14 16:54:20 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main ( void )
{
	Bureaucrat a("Raph", 1);
	Bureaucrat b("Laurent", 15);
	Form f1;
	Form f2;

	std::cout << std::endl << "Bienvenue à The Office!" << std::endl;
	std::cout << std::endl;
	std::cout << "Nous avons acutellement 2 employés :" << std::endl;
	std::cout << "> " << a;
	std::cout << "> " << b;
	std::cout << std::endl;
	std::cout << "Nous avons 1 Formulaires à disposition :" << std::endl;
	std::cout << "> " << f1;
	try
	{
		Bureaucrat tmp(b);
		std::cout << std::endl;
		
		std::cout << tmp.getName() << " tente de signer " << f1.getName() << " :" << std::endl;
		tmp.signForm(f1);
		std::cout << "> " << f1;
		
		std::cout << std::endl;

		std::cout << tmp.getName() << " tente à nouveau de signer " << f1.getName() << " :" << std::endl;
		tmp.signForm(f1);
		std::cout << "> " << f1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}