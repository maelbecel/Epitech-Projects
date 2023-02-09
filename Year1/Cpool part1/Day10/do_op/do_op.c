/*
** EPITECH PROJECT, 2021
** do_op
** File description:
** xxx
*/

#include "../include/my.h"

void    do_op(char **av)
{
    if (av[2][0] == '+')
        my_put_nbr(my_getnbr(av[1]) + my_getnbr(av[3]));
    if (av[2][0] == '*')
        my_put_nbr(my_getnbr(av[1]) * my_getnbr(av[3]));
    if (av[2][0] == '%')
        my_put_nbr(my_getnbr(av[1]) % my_getnbr(av[3]));
    if (av[2][0] == '/')
        my_put_nbr(my_getnbr(av[1]) / my_getnbr(av[3]));
    if (av[2][0] == '-')
        my_put_nbr(my_getnbr(av[1]) - my_getnbr(av[3]));
}

int    main(int argc, char **argv)
{
    if (argc != 4)
        return (84);
    if (argv[2][0] != 37 && argv[2][0] != 42 &&
        argv[2][0] != 43 && argv[2][0] != 45 &&
        argv[2][0] != 47) {
        my_put_nbr(0);
        my_putchar('\n');
        return (84);
    }
    if (argv[2][0] == 47 && my_getnbr(argv[3]) == 0) {
        my_putstr("Stop: division by zero\n");
        return (84);
    }
    if (argv[2][0] == 37 && my_getnbr(argv[3]) == 0) {
        my_putstr("Stop: modulo by zero\n");
        return (84);
    }
    do_op(argv);
    my_putchar('\n');
    return (0);
}
