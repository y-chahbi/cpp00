# include "PhoneBook.hpp"

int main(int ac, char **av)
{
    PhoneBook   book;
    Contact     contact[8];
    int         i;

    i = 0;
    while (1)
    {
        book.fill(i, contact);
        i++;
    }
}