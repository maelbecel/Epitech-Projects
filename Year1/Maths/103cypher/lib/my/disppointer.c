/*
** EPITECH PROJECT, 2021
** disppointer.c
** File description:
** disppointer.c
*/

#include "my.h"

void disppointer(va_list *arg)
{
    long long ptr = va_arg(*arg, long long);
    my_putstr("0x");
    my_put_nbr_base(ptr, "0123456789abcdef");
}