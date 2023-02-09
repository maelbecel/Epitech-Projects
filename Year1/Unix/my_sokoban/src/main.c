/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "sokoban.h"

static void help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tmap file representing the warehouse map, containing '#'");
    my_putstr(" for walls, \n");
    my_putstr("\t'P' for the player, 'X' for boxes and");
    my_putstr(" 'O' for storage locations.\n");
}

int main (int ac, char **argv)
{
    if (ac == 2) {
        if (my_strcmp(argv[1], HELP_FLAG) == 0) {
            help();
            exit(0);
        }
        return my_sokoban(argv[1]);
    } else if (ac == 1)
        my_exit(ERROR_FEW_ARG, 84);
    else
        my_exit(ERROR_MNY_ARG, 84);
    return 84;
}

