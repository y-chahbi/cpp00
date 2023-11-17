# ifndef PHONENOOK_HPP
# define PHONENOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:
		std::string	cmd;
		std::string	f_name;
		std::string	l_name;
		std::string nickname;
		std::string p_number;
		std::string	darkest_secret;
		int			_index;
		int _fill;
		void	welcom()
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
		void	add(int i, Contact contact[8])
		{
			std::cout << "Enter The First Name\n";
			std::cin >> f_name;
			std::cout << "Enter The Last Name\n";
			std::cin >> l_name;
			std::cout << "Enter The Nikename\n";
			std::cin >> nickname;
			std::cout << "Enter The Phone Number\n";
			std::cin >> p_number;
			std::cout << "Enter The Darkest Secret\n";
			std::cin >> darkest_secret;
			contact[i].fill_s(f_name, l_name, nickname, p_number, darkest_secret, i);
			_fill = 1;
		}
		void	show_four(Contact contact[8])
		{
			int tor = 0;
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
				std::cout << "Enter the index to see all the details!" << std::endl;
				std::cout << "To quite Search enter 9!" << std::endl;
				std::cin >> _index;
				if (_index == 9)
					break ;
				contact[_index].show_contact();
			}
		}	
		void	search(Contact contact[8])
		{
			show_four(contact);
		}
		void	fexit()
		{
			exit(1);
		}
		void	fill(int i, Contact contact[8])
		{
			welcom();
			while (!_fill)
			{
				std::cout << "Enter the command" << std::endl;
				std::cin >> cmd;
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
};

# endif