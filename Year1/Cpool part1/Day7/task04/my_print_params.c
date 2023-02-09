/*
** EPITECH PROJECT, 2020
** my_print_params
** File description:
** d
*/

#include <unistd.h>

void my_putchar(char c);
void my_putstr(char *x);

int my_print_params(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
    return (0);
}
