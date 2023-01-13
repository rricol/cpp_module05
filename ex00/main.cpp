/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:25:03 by rricol            #+#    #+#             */
/*   Updated: 2023/01/13 12:02:42 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main ( void )
{
	Bureaucrat a("Raph", 1);
	Bureaucrat b("Laurent", 15);
	Bureaucrat c;

	std::cout << "Bienvenue à l'Office!" << std::endl;
	std::cout << "Nous avons acutellement 3 employés :" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << std::endl;
	return 0;
}