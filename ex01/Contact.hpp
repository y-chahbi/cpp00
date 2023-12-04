/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:23:24 by ychahbi           #+#    #+#             */
/*   Updated: 2023/12/04 10:41:00 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
	private:
		std::string	f_name, l_name, nickname, p_number, darkest_secret, _f;
		std::string	_l;
		std::string	_p;
	public:
		int	index;

		void	show_four_contact();
		void	show_contact();
		void	fill_s(std::string _f_name, std::string	_l_name, std::string _nickname, std::string _p_number, std::string _darkest_secret, int i);
};

#endif