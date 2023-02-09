/*
** EPITECH PROJECT, 2022
** get_balise_content.c
** File description:
** get_balise_content
*/

#include "parser.h"

char *get_balise_from_place(char *content, int i)
{
    char *balise = malloc(sizeof(char) * my_strlen(content));
    size_t x = 0;

    for (; content[i] != '<'; i--);
    i++;
    for (; content[i] != ' '; i++) {
        balise[x++] = content[i];
    }
    balise[x] = '\0';
    return balise;
}
