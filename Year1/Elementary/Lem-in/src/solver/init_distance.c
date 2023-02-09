/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-lemin-lucas.iglesia
** File description:
** init distance between rooms
*/

#include "my.h"
#include "printf.h"
#include "lemin.h"

static void get_distance_for_next(room_t *room)
{
    if (room->next == NULL) {
        room->is_visited = true;
        return;
    }
    for (int i = 0; room->next[i]; i++) {
        if (room->next[i]->is_visited == true)
            continue;
        if (room->distance + 1 < room->next[i]->distance)
            room->next[i]->distance = room->distance + 1;
    }
    room->is_visited = true;

}

static void get_distance(room_t **rooms_array, int size,
                            size_t room_check)
{
    int smaller_distance = -1;
    int room_nb = -1;

    for (int i = 0; i < size; i++) {
        if (rooms_array[i]->is_visited == true)
            continue;
        if (rooms_array[i]->distance < smaller_distance ||
        smaller_distance == -1) {
            room_nb = i;
            smaller_distance = rooms_array[i]->distance;
        }
    }
    if (room_nb != -1) {
        get_distance_for_next(rooms_array[room_nb]);
        get_distance(rooms_array, size, room_check + 1);
    }
}

void init_distance(lemin_t *lemin)
{
    for (int i = 0; i < lemin->size; i++) {
        if (lemin->room[i] != lemin->end)
            lemin->room[i]->distance = 1000000;
        else
            lemin->room[i]->distance = 0;
    }
    get_distance(lemin->room, lemin->size, 0);
}
