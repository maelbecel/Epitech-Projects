/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-lemin-lucas.iglesia
** File description:
** lemin
*/

#include "my.h"
#include "printf.h"
#include "lemin.h"

room_t *find_start(room_t **room)
{
    for (int i = 0; room[i] != NULL; i++) {
        if (room[i]->start == true)
            return room[i];
    }
    return NULL;
}

room_t *find_end(room_t **room)
{
    for (int i = 0; room[i] != NULL; i++) {
        if (room[i]->end == true)
            return room[i];
    }
    return NULL;
}

room_t *find_room_pt2(char *input, room_t *room, int *nb, room_t **other)
{
    char *name = NULL;
    if (is_link(input) && my_strcmp(get_name(input),
                                            room->name) == 0) {
        if (*nb == 0) {
            name = get_second_name(input);
            return (name == NULL) ? NULL : find_next(name, other);
        } else
            *nb -= 1;
    }
    free(name);
    return NULL;
}
