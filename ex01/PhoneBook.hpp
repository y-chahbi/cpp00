/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:23:30 by ychahbi           #+#    #+#             */
/*   Updated: 2023/11/20 10:35:59 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONENOOK_HPP
# define PHONENOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
	public:
		std::string	cmd, f_name, l_name, nickname, p_number, darkest_secret;
		std::string	_index;
		int _fill;

		void	welcom();
		int		check_nums(std::string s);
		void	add(int i, Contact contact[8]);
		void	show_four(Contact contact[8]);	
		void	search(Contact contact[8]);
		void	fill(int i, Contact contact[8]);
};

# endif
