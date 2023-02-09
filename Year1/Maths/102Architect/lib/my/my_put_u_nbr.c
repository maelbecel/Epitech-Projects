/*
** EPITECH PROJECT, 2021
** my_put_u_nbr.c
** File description:
** put u nbr
*/

void my_putchar(char c);

unsigned int my_put_u_nbr(unsigned int nb)
{
    unsigned int i = 0;

    if (nb > 9) {
        i = nb % 10;
        nb /= 10;
        my_put_u_nbr(nb);
        my_putchar(i + 48);
    } else
        my_putchar(nb + 48);
    return 0;
}
