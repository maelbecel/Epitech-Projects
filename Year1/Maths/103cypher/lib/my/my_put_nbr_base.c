/*
** EPITECH PROJECT, 2021
** my_put_nbr_base.c
** File description:
** my_putnbr_base
*/

void my_putchar(char c);
int my_strlen(char const *str);

void my_put_nbr_base(long nbr, char *base)
{
    long division = 1;
    long res = 0;
    long to_base = my_strlen(base);

    if (nbr < 0) {
        my_putchar('-');
        nbr = - nbr;
    }
    for (;(nbr / division) >= to_base;) {
        division = division * to_base;
    }
    for (;division > 0;) {
        res = (nbr / division) % to_base;
        my_putchar(base[res]);
        division = division / to_base;
    }
}