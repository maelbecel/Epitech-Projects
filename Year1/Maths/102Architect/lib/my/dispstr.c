/*
** EPITECH PROJECT, 2021
** my_dispstr
** File description:
** dispstr
*/

#include "my.h"

void dispstr(va_list *arg)
{
    char *str = va_arg(*arg, char *);
    my_putstr(str);
}