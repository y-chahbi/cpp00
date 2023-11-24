/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:23:27 by ychahbi           #+#    #+#             */
/*   Updated: 2023/11/24 10:24:12 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

int main()
{
    PhoneBook   book;
    Contact     contact[8];
    int         i;

    i = 0;
    while (1)
    {
        book.fill(i, contact);
        i++;
        i = i % 8;
    }
}