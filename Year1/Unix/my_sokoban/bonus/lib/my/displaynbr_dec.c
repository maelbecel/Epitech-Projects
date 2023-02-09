/*
** EPITECH PROJECT, 2021
** displaychar.c
** File description:
** display char
*/

#include <stdio.h>
#include <stdarg.h>
#include "my.h"

void my_put_nbr_dec(int nb)
{
    int i = 0;

    if (nb > 9) {
        i = nb % 10;
        nb /= 10;
        my_put_nbr(nb);
        my_putchar(i + 48);
    } else
        my_putchar(nb + 48);
}

int displaynbr_dec(va_list argv)
{
    unsigned int nb = va_arg(argv, unsigned int);
    int i = 0;

    if (nb > 9) {
        i = nb % 10;
        nb /= 10;
        my_put_nbr_dec(nb);
        my_putchar(i + '0');
    } else
        my_putchar(nb + '0');
    return 0;
}
