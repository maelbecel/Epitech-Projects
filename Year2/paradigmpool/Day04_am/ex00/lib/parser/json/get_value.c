/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "parser.h"

char *get_value(char *line, char *var)
{
    int i = 0;
    char *str = line + my_strlen(var);

    while (str[i++] != '\n');
    str[i - 1] = '\0';
    if (str[i - 2] == ',')
        str[i - 2] = '\0';
    return str;
}
