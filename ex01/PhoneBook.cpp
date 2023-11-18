/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:23:21 by ychahbi           #+#    #+#             */
/*   Updated: 2023/11/18 11:40:01 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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

void	PhoneBook::add(int i, Contact contact[8])
{
	std::cout << "Enter The First Name" << std::endl;
	std::getline(std::cin, f_name);
	std::cout << "Enter The Last Name" << std::endl;
	std::getline(std::cin, l_name);
	std::cout << "Enter The Nikename" << std::endl;
	std::getline(std::cin, nickname);
	std::cout << "Enter The Phone Number" << std::endl;
	std::getline(std::cin, p_number);
	std::cout << "Enter The Darkest Secret" << std::endl;
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
void	PhoneBook::show_four(Contact contact[8])
{
	int tor = 0;
	int	__index;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|  index   |first Name|last Name | phone num|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	while ( tor < 4 && tor == contact[tor].index)
	{
		contact[tor].show_four_contact();
		tor++;
	}
	while (1)
	{
		std::cout << "Enter the index to see all the details! BREAK to exit!" << std::endl;
		std::getline(std::cin, _index);
		if (std::cin.eof())
			fexit();
		__index = std::atoi(_index.c_str());
		if (__index >= 0 && __index < 9 && _index.compare("BREAK") != 0 && !contact[__index].f_name.empty() && !_index.empty() && check_nums(_index) != 0)
			contact[__index].show_contact();
		else if(_index.compare("BREAK") == 0)
			break;
		else
			std::cout << "Try Again and Read tearms!" << std::endl;
	}
}
void	PhoneBook::search(Contact contact[8])
	{
		show_four(contact);
	}
void	PhoneBook::fexit()
{
	exit(1);
}
void	PhoneBook::fill(int i, Contact contact[8])
{
	welcom();
	while (!_fill)
	{
		std::cout << "Enter the command" << std::endl;
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			fexit();
		if (!cmd.compare("ADD") || !cmd.compare("SEARCH") || !cmd.compare("EXIT"))
		{
			if (!cmd.compare("ADD"))
				add(i, contact);
			if (!cmd.compare("SEARCH"))
				search(contact);
			if (!cmd.compare("EXIT"))
				fexit();
		}
		else
		{
			std::cout << "CMD ERROR!" << std::endl;
		}
	}
}
