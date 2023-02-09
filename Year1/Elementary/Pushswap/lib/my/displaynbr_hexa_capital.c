/*
** EPITECH PROJECT, 2021
** displaynbr_hexa_capital.c
** File description:
** display number in hexa base capital
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

void my_putinhexa_capital(int nb)
{
    int quotient = nb;
    int r;
    char *base = "0123456789ABCDEF";
    char *res = malloc(16 * 10000);
    int j = 0;

    while (quotient != 0) {
        r = quotient % 16;
        res[j] = base[r];
        quotient /= 16;
        j++;
    }

    for (int i = j; i >= 0; i--) {
        my_putchar(res[i]);
    }
}

void displaynbr_hexa_capital(va_list argv)
{
    int nb = va_arg(argv, int);
    my_putinhexa_capital(nb);
}

void displaynbr_hexa_capital_hashtag(va_list argv)
{
    int nb = va_arg(argv, int);
    my_putchar('0');
    my_putchar('X');
    my_putinhexa_capital(nb);
}