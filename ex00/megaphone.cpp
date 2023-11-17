#include <iostream>

class write 
{
    public:
        int         nums;
        std::string ags;

        void    to_upper()
        {
            int i;

            i = 0;
            while (i < ags.length())
            {
                ags.at(i) = toupper(ags.at(i));
                i++;
            }
        }

        void    fill(int ac, char **av)
        {
            int i;

            if (ac == 1)
                ags = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
            else
            {
                i = 2;
                ags = av[1];
                while (i < ac)
                {
                    ags.append(av[i++]);
                }
                to_upper();
            }
        }
};

int main(int ac, char **av)
{
    write   wop;

    wop.fill(ac, av);
    std::cout << wop.ags;
}