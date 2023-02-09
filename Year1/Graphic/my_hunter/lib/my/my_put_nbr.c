/*
** EPITECH PROJECT, 2021
** my_print_digits.c
** File description:
** print digits in ascending order
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int i = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb > 9) {
        i = nb % 10;
        nb /= 10;
        my_put_nbr(nb);
        my_putchar(i + 48);
    } else
        my_putchar(nb + 48);
    return 0;
}
