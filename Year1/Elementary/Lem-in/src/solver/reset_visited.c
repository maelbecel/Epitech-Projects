/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-lemin-lucas.iglesia
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "lemin.h"

void reset_visited(lemin_t *lemin)
{
    for (int i = 0; i < lemin->size; i++)
        lemin->room[i]->is_visited = false;
}
