/*
** EPITECH PROJECT, 2022
** env
** File description:
** env
*/

#include "my.h"
#include "printf.h"
#include "shell.h"

void my_puterror(char *string)
{
    write(2, string, my_strlen(string));
}

int char_alpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return 1;
    return 0;
}

int char_num(char c)
{
    if ((c >= '0' && c <= '9'))
        return 1;
    return 0;
}

int is_alpha_num(char *string)
{
    for (int i = 0; i < my_strlen(string); i++) {
        if (!(char_alpha(string[i]) ||
                char_num(string[i]) || string[i] == '_'))
            return 0;
    }
    return 1;
}

void print_arg(char **arg)
{
    while (* arg ) {
        my_putstr(* arg );
        my_putchar('\n');
        arg++;
    }
}
