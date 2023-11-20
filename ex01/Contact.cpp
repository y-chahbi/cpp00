/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:23:17 by ychahbi           #+#    #+#             */
/*   Updated: 2023/11/20 10:36:35 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::show_four_contact()
{
    if (!_f.empty())
	{
        std::cout << "|     " << index << "    |"
	    << std::right << std::setw(10) << _f << "|"
	    << std::right << std::setw(10) << _l << "|"
	    << std::right << std::setw(10) << _p << "|"
	    << std::endl;
    }
    else
        std::cout << "|             NO CONTACT FOR NOW            |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

void	Contact::show_contact()
{
    std::cout << "Index " << index << std::endl;
	std::cout << "First Name :";
	std::cout << f_name << std::endl;
	std::cout << "Last Name :";
	std::cout << l_name << std::endl;
	std::cout << "NickName :";
	std::cout << nickname << std::endl;
	std::cout << "PhoneNumber :";
	std::cout << p_number << std::endl;
	std::cout << "DarkestSecret :";
	std::cout << darkest_secret << std::endl;
}

void	Contact::fill_s(std::string _f_name, std::string	_l_name, std::string _nickname, std::string _p_number, std::string _darkest_secret, int i)
{
	f_name			= _f_name;
	l_name			= _l_name;
	nickname		= _nickname;
	p_number		= _p_number;
	darkest_secret	= _darkest_secret;
    _f = _f_name.length() >= 10 ? _f_name.substr(0,9).append(".") : _f = _f_name;
    _l = _l_name.length() >= 10 ? _l_name.substr(0,9).append(".") : _l = _l_name;
    _p = _p_number.length() >= 10 ? _p_number.substr(0,9).append(".") : _p = _p_number;
    index = i % 8;
	show_contact();
}