/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:25:03 by rricol            #+#    #+#             */
/*   Updated: 2023/01/14 12:41:06 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main ( void )
{
	Bureaucrat a("Raph", 1);
	Bureaucrat b("Laurent", 15);
	Bureaucrat c;

	std::cout << std::endl << "Bienvenue à The Office!" << std::endl;
	std::cout << std::endl;
	std::cout << "Nous avons acutellement 3 employés :" << std::endl;
	std::cout << "> " << a;
	std::cout << "> " << b;
	std::cout << "> " << c;
	std::cout << std::endl;
	try
	{
		Bureaucrat tmp(b);
		int	grade = 15;
		std::cout << std::endl;
		
		std::cout << "Tentons de promouvoir " << tmp.getName() << " de " << grade << " grade" << std::endl;
		tmp.upGrade(grade);
		std::cout << "> " << tmp;
		
		std::cout << std::endl;
		
		std::cout << "Tentons de retrograder " << tmp.getName() << " de " << grade << " grade" << std::endl;
		tmp.downGrade(grade);
		std::cout << "> " << tmp;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}