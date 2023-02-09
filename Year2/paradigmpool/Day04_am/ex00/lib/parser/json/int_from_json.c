/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "parser.h"

int int_from_json(char *file, char *var)
{
    int value = 0;
    char *parse = NULL;

    parse = parser(file, var);
    if (parse == NULL)
        return -1;
    value = my_getnbr(parse);
    return value;
}
