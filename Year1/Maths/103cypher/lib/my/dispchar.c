/*
** EPITECH PROJECT, 2021
** dispchar.c
** File description:
** dispchar
*/

#include "my.h"

void dispchar(va_list *arg)
{
    int c = va_arg(*arg, int);
    my_putchar(c);
}