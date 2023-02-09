/*
** EPITECH PROJECT, 2021
** dispabs.c
** File description:
** dispabs
*/

#include "my.h"

void dispunsigned(va_list *arg)
{
    unsigned int nb = va_arg(*arg, unsigned int);

    my_put_u_nbr(nb);
}