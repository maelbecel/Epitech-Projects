/*
** EPITECH PROJECT, 2021
** displaynbr_octal.c
** File description:
** display nbr in octal
*/

#include <stdio.h>
#include <stdarg.h>

int my_getinoctal(int nb)
{
    int quotient = nb;
    int r;
    char *base = "01234567";
    int res = 0;
    int x = 1;
    int j = 0;

    if (nb < 0){
        quotient = quotient * -1;
        my_putchar('-');
        j += 1;
    }
    while (quotient != 0) {
        r = quotient % 8;
        res += r * x;
        quotient /= 8;
        j++;
        x *= 10;
    }
    return res;
}

void displaynbr_octal(va_list argv)
{
    unsigned int nb = va_arg(argv, unsigned int);
    my_put_nbr(my_getinoctal(nb));
}

void displaynbr_octal_hashtag(va_list argv)
{
    my_putchar('0');
    displaynbr_octal(argv);
}
