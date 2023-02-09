/*
** EPITECH PROJECT, 2021
** dispbin.c
** File description:
** dispbin
*/

#include "my.h"
#include <stdlib.h>

void dispbin(va_list *arg)
{
    int nb = va_arg(*arg, int);
    my_put_nbr_base(nb, "01");
}
