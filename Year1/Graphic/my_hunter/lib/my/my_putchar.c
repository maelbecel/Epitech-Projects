/*
** EPITECH PROJECT, 2021
** my_print_digits.c
** File description:
** print digits in ascending order
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
