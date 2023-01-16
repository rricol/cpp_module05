/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:25:03 by rricol            #+#    #+#             */
/*   Updated: 2023/01/16 15:49:42 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_settings.h"

int main ( void )
{
	try
	{
		// AForm x(); // pour tester que la classe AForm soit bien abstraite
		Bureaucrat a("Raphaël", 1);
		Bureaucrat b("Laurent", 60);
		Bureaucrat c("Tito", 15);
		// Bureaucrat d("Lucas", 160); // erreur initialisation grade
		PresidentialPardonForm f1("Dark Vador");
		RobotomyRequestForm f2("Votre belle-mère");
		ShrubberyCreationForm f3("Seulout");
		std::cout << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;
		std::cout << f1;
		std::cout << f2;
		std::cout << f3;

		// b.signForm(f3); // erreur signature grade too high
		a.signForm(f1);
		b.signForm(f2); // commenter pour obtenir erreur execution formulaire non signé
		c.signForm(f3);
		std::cout << std::endl;
		std::cout << f1;
		std::cout << f2;
		std::cout << f3;
		// a.signForm(f2); // erreur Formulaire déjà signé
		std::cout << std::endl;
		// b.executeForm(f3); // erreur execution grade too low
		a.executeForm(f3);
		b.executeForm(f1);
		c.executeForm(f2);
		std::cout << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}