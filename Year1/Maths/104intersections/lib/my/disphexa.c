/*
** EPITECH PROJECT, 2021
** disphexa.c
** File description:
** disphexa
*/

#include "my.h"

void disphexa(va_list *arg)
{
    int nb = va_arg(*arg, int);
    my_put_nbr_base(nb, "0123456789abcdef");
}