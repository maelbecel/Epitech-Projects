/*
** EPITECH PROJECT, 2021
** dispint.c
** File description:
** dispint
*/

#include "my.h"

void dispint(va_list *arg)
{
    int d = va_arg(*arg, int);
    my_put_nbr(d);
}