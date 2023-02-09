/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-lemin-lucas.iglesia
** File description:
** solver
*/

#include "my.h"
#include "printf.h"
#include "lemin.h"

static void check_distance(room_t *room, int (*i), int (*distance),
                            int (*pos_next))
{
    if (room->distance + room->have_ant < (*distance) ||
    (room->distance + room->have_ant == (*distance) && !room->have_ant)) {
        (*pos_next) = (*i);
        (*distance) = room->distance + room->have_ant;
    }
}

static bool move_ant(lemin_t *lemin, ant_t *ant)
{
    int distance = 1000000;
    int pos_next = -1;
    room_t *room = NULL;

    for (int i = 0; ant->room->next[i] != NULL; i++) {
        room = ant->room->next[i];
        if (ant->room->next[i] == lemin->end) {
            pos_next = i;
            break;
        }
        check_distance(room, &i, &distance, &pos_next);
    }
    if (pos_next != -1 && !ant->room->next[pos_next]->have_ant) {
        if (ant->room->next[pos_next] != lemin->end)
            ant->room->next[pos_next]->have_ant = true;
        ant->room->have_ant = false;
        ant->room = ant->room->next[pos_next];
        return true;
    }
    return false;
}

void solver(lemin_t *lemin, ant_t *ants)
{
    size_t ants_moved = 0;
    bool first_ant = true;

    for (int moved = 0; moved < lemin->nbr_ant; moved++) {
        if (ants[moved].room == lemin->end)
            continue;
        ants_moved++;
        if (!move_ant(lemin, &ants[moved])) {
            display_movement(ants[moved - 1], ants[moved - 1].room->name);
            break;
        }
        display_result(lemin, ants, moved, first_ant);
        first_ant = false;
    }
    if (ants_moved != 0) {
        my_putchar('\n');
        solver(lemin, ants);
    }
}
