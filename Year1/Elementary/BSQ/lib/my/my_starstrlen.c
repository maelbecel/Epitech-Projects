/*
** EPITECH PROJECT, 2021
** my_starstrlen.c
** File description:
** get size of str str
*/

#include <stdio.h>

int my_starstrlen(char **starstr)
{
    int i = 0;

    while (starstr[i] != NULL)
        i++;
    return i;
}