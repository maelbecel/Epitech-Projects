/*
** EPITECH PROJECT, 2021
** my_print_isneg.c
** File description:
** xxx
*/

void my_putchar(char c);

int my_isneg (int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
}
