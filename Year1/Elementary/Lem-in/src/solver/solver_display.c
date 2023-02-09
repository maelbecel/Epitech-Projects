/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-lemin-lucas.iglesia
** File description:
** display of solver
*/

#include "my.h"
#include "printf.h"
#include "lemin.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void display_movement(ant_t ant, char *room_name)
{
    my_printf("P%d-%s", ant.nb, room_name);
}

void display_result(lemin_t *lemin, ant_t *ants, int moved, bool first_ant)
{
    if (!first_ant) {
        display_movement(ants[moved - 1], ants[moved - 1].room->name);
        my_putchar(' ');
    }
    if (moved == lemin->nbr_ant - 1)
        display_movement(ants[moved], ants[moved].room->name);
}
