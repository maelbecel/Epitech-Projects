/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "parser.h"

char *parser(char *file, char *var)
{
    FILE *fd = fopen(file, "r");
    char *variable = format("    \"%s\": ", var);
    return get_line_pars(fd, variable);
}
