/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:23:30 by ychahbi           #+#    #+#             */
/*   Updated: 2023/12/09 12:44:47 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONENOOK_HPP
# define PHONENOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		std::string	cmd, f_name, l_name, nickname, p_number, darkest_secret;
		std::string	_index;
		Contact     contact[8];
	public:
		int _fill;

		void	welcom();
		int		check_nums(std::string s);
		void	add(int i);
		void	show_four();	
		void	search();
		void	fill(int i);
};

# endif
