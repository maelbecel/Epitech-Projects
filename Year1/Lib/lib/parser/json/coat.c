/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "parser.h"

char *coat(void)
{
    char *coat = malloc(sizeof(char) * 2);

    if (!coat)
        return NULL;
    coat[0] = '"';
    coat[1] = '\0';
    return (coat);
}
