/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "parser.h"

char **str_array_from_json(char *file, char *var)
{
    if (parser(file, var) == NULL)
        return NULL;
    return my_str_to_word_array(clean_string(parser(file, var)), ',');
}
