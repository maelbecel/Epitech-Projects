/*
** EPITECH PROJECT, 2021
** usage.c
** File description:
** usage.c
*/

#include "bistromatic.h"

void print_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("./calc base operators size_read\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("- base: all the symbols of the base\n");
    my_putstr("- operators: the symbols for ");
    my_putstr("the parentheses and the 5 operators\n");
    my_putstr("- size_read: number of characters to be read\n");
}

void usage(char **av)
{
    if (my_strcmp(av[1], "-h") == 0) {
        print_usage();
        return (EXIT_USAGE);
    }
}