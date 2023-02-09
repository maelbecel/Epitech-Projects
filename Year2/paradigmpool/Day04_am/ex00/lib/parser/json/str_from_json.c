/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "parser.h"

char *str_from_json(char *file, char *var)
{
    if (parser(file, var) == NULL)
        return NULL;
    return clean_string(parser(file, var));
}
