/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _settings.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:19:15 by rricol            #+#    #+#             */
/*   Updated: 2023/01/16 15:11:06 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SETTINGS_H
#define _SETTINGS_H

#include <fstream>
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define	BOLD_BLACK	"\033[1m\033[30m"
#define BOLD_RED	"\033[1m\033[31m"
#define BOLD_G		"\033[1m\033[32m"
#define BOLD_B		"\033[1m\033[34m"
#define BOLD_P		"\033[1m\033[35m"
#define	RESET   	"\033[0m"
#define BOLD_Y		"\033[1m\033[33m"
#define BOLD_W		"\033[1m\033[37m"
#define LOG			BOLD_BLACK << "[ Log ] " << RESET
#define SUCCESS		BOLD_G << "[ Success ] " << RESET
#define INFO		BOLD_B << "[ Info ] " << RESET
#define ERROR		BOLD_RED << "[ Error ] " << RESET
#define WARNING		BOLD_Y << "[ Warning ] " << RESET

class Bureaucrat;
class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

#endif // _SETTINGS_H
