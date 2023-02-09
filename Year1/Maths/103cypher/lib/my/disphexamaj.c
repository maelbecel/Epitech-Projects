/*
** EPITECH PROJECT, 2021
** dispHEXA.c
** File description:
** dispHEXA
*/

#include "my.h"

void disphexamaj(va_list *arg)
{
    int nb = va_arg(*arg, int);
    my_put_nbr_base(nb, "0123456789ABCDEF");
}