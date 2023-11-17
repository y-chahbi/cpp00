# ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	public:
		std::string	f_name;
		std::string	l_name;
		std::string nickname;
		std::string p_number;
		std::string	darkest_secret;
		std::string	_f;
		std::string	_l;
		std::string	_p;
		int	index;

		void	show_four_contact()
		{
			std::cout << "|     " << index << "    |"
			<< _f << "|"
			<< _l << "|"
			<< _p << "|"
			<< std::endl;
			std::cout << "---------------------------------------------" << std::endl;

		}
		void	show_contact()
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
		void	fill_s(std::string _f_name, std::string	_l_name, std::string _nickname, std::string _p_number, std::string _darkest_secret, int i)
		{
			f_name			= _f_name;
			l_name			= _l_name;
			nickname		= _nickname;
			p_number		= _p_number;
			darkest_secret	= _darkest_secret;
            _f = _f_name.length() >= 10 ? _f_name.substr(0,9).append(".") : _f_name.insert(_f_name.length() , 10 - _f_name.length(), 32);
            _l = _l_name.length() >= 10 ? _l_name.substr(0,9).append(".") : _l_name.insert(_l_name.length() , 10 - _l_name.length(), 32);
            _p = _p_number.length() >= 10 ? _p_number.substr(0,9).append(".") : _p_number.insert(_p_number.length() , 10 - _p_number.length(), 32);
            index = i % 8;
			show_contact();
		}
};

#endif