/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-lemin-lucas.iglesia
** File description:
** find_pos
*/

#include "my.h"
#include "printf.h"
#include "lemin.h"

int find_x(char *str)
{
    int i = 0;

    for (; str[i] != ' '; i++);
    return my_getnbr(str + i);
}

int find_y(char *str)
{
    int i = 0;

    for (; str[i] != ' '; i++);
    i++;
    for (; str[i] != ' '; i++);
    return my_getnbr(str + i);
}

bool is_start(char **input, int nb)
{
    if (my_strcmp(input[nb - 1], "##start\n") == 0)
        return true;
    return false;
}

bool is_end(char **input, int nb)
{
    if (my_strcmp(input[nb - 1], "##end\n") == 0)
        return true;
    return false;
}
