/*
** EPITECH PROJECT, 2021
** displaystr_unprintale
** File description:
** display str unprintable charactere
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "my.h"
#include <stdlib.h>

void displayoctal(int nb)
{
    int quotient = nb;
    int r;
    char *base = "01234567";
    char *res = malloc(20);
    int j = 0;

    while (quotient != 0) {
        r = quotient % 8;
        res[j] = base[r];
        quotient /= 8;
        j++;
    }
    for (; my_strlen(res) != 3; j++)
        res[j] = '0';

    for (int i = j; i >= 0; i--) {
        my_putchar(res[i]);
    }
}

void displaystr_unprintable(va_list argv)
{
    char *str = va_arg(argv, char*);

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            displayoctal(str[i]);
        } else
            my_putchar(str[i]);
    }
}
