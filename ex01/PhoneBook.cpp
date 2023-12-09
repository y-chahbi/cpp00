/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:23:21 by ychahbi           #+#    #+#             */
/*   Updated: 2023/12/09 13:06:42 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int checkspaces(std::string theword)
{
	for (unsigned long i = 0; i < theword.length(); i++)
		if (theword.at(i) != 32)
			return (0);
	return (1);
}

int	checkEmptyString(std::string str, int *re)
{
	if (std::cin.eof())
		exit(1);
	if ((str.empty() && *re == 0) || (str.empty() && *re == 1) || checkspaces(str))
		return (std::cout << "The Field can't be Empty!" << std::endl, 1);
	return (*re = 0, 0);
}

void PhoneBook::welcom()
{
	_fill = 0;
	std::cout << "|----------------------------|" << std::endl;
	std::cout << "|Welcom To PhoneBook Rigester|" << std::endl;
	std::cout << "|here is the avilable options|" << std::endl;
	std::cout << "|ADD -> to add to the contact|" << std::endl;
	std::cout << "|SEARCH --> search in contact|" << std::endl;
	std::cout << "|EXIT -> to close the program|" << std::endl;
	std::cout << "|----------------------------|" << std::endl;
}

void	PhoneBook::add(int i)
{
	int		repted = 0;

	std::cout << "Enter The First Name" << std::endl;
	std::getline(std::cin, f_name);
	while (checkEmptyString(f_name, &repted))
		std::getline(std::cin, f_name);
		
	std::cout << "Enter The Last Name" << std::endl;
	std::getline(std::cin, l_name);
	while (checkEmptyString(l_name, &repted))
		std::getline(std::cin, l_name);
		
	std::cout << "Enter The Nikename" << std::endl;
	std::getline(std::cin, nickname);
	while (checkEmptyString(nickname, &repted))
		std::getline(std::cin, nickname);
		
	std::cout << "Enter The Phone Number" << std::endl;
	std::getline(std::cin, p_number);
	while (checkEmptyString(p_number, &repted))
		std::getline(std::cin, p_number);
		
	std::cout << "Enter The Darkest Secret" << std::endl;
	std::getline(std::cin, darkest_secret);
	while (checkEmptyString(darkest_secret, &repted))
		std::getline(std::cin, darkest_secret);
		
	contact[i].fill_s(f_name, l_name, nickname, p_number, darkest_secret, i);
	_fill = 1;
}

int		PhoneBook::check_nums(std::string s)
{
	for (unsigned long i = 0; i < s.length(); i++)
	{
		if (!isdigit(s.at(i)))
			return (0);
	}
	return (1);
}

void	PhoneBook::show_four()
{
	int tor = 0;
	int	__index;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << std::right << std::setw(10) <<  "index";
	std::cout << "|" << std::right << std::setw(10) <<  "first Name";
	std::cout << "|" << std::right << std::setw(10) <<  "last Name";
	std::cout << "|" << std::right << std::setw(10) <<  "NickName" << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	while ( tor < 8 && tor == contact[tor].index)
	{
		contact[tor].show_four_contact();
		tor++;
	}
	while (1)
	{
		std::cout << "Enter the index to see all the details! BREAK to exit!" << std::endl;
		std::getline(std::cin, _index);
		if (std::cin.eof())
			exit(1);
		__index = std::atoi(_index.c_str());
		if (__index >= 0 && __index < 8 && _index.compare("BREAK") != 0 && !f_name.empty()
			&& !_index.empty() && check_nums(_index) != 0
				&& __index == contact[__index].index)
			contact[__index].show_contact();
		else if(_index.compare("BREAK") == 0)
		{
			welcom();
			break;
		}
		else
			std::cout << "Try Again and Read tearms!" << std::endl;
	}
}

void	PhoneBook::search()
{
	show_four();
}

void	PhoneBook::fill(int i)
{
	welcom();
	while (!_fill)
	{
		std::cout << "Enter the command" << std::endl;
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			exit(1);
		if (!cmd.compare("ADD") || !cmd.compare("SEARCH") || !cmd.compare("EXIT"))
		{
			if (!cmd.compare("ADD"))
				add(i);
			if (!cmd.compare("SEARCH"))
				search();
			if (!cmd.compare("EXIT"))
				exit(0);
		}
		else
		{
			std::cout << "CMD ERROR!" << std::endl;
		}
	}
}
