/*
** EPITECH PROJECT, 2021
** dispoct.c
** File description:
** dispoct
*/

#include "my.h"

void dispoct(va_list *arg)
{
    int nb = va_arg(*arg, int);
    my_put_nbr_base(nb, "01234567");
}