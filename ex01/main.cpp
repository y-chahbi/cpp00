/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:23:27 by ychahbi           #+#    #+#             */
/*   Updated: 2023/11/26 17:41:26 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

int main()
{
    PhoneBook   book;
    int         i;

    i = 0;
    while (1)
    {
        book.fill(i);
        i++;
        i = i % 8;
    }
}