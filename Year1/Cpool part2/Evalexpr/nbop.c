/*
** EPITECH PROJECT, 2021
** nbop.c
** File description:
** evalex
*/

#include <my.h>

int nbop(char *av)
{
    int i = 0;
    int nb = 0;

    if (av[0] == '-')
        i++;
    for (i; av[i] != '\0'; i++){
        if (av[i] < '0'){
            i++;
            nb += 1;
        }
    }
    return nb;
}
