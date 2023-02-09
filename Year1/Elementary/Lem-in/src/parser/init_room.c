/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-lemin-lucas.iglesia
** File description:
** init_room
*/

#include "my.h"
#include "printf.h"
#include "lemin.h"

int room(char *input, int *n, int i)
{
    if (input[0] != '#') {
        if (is_room(input) && *n > 0)
            *n -= 1;
        else if (is_room(input) && *n == 0)
            return i;
    }
    return 0;
}

int find_room(char **input, int n)
{
    int i = 1;
    int nb = 0;

    for (; input[i]; i++) {
        nb = room(input[i], &n, i);
        if (nb != 0)
            return i;
    }
    return 0;
}

static char *get_room_name(char *str)
{
    char *name = malloc(sizeof(char) * my_strlen(str));
    int i = 0;

    if (name == NULL)
        return NULL;
    for (; str[i] != ' '; i++) {
        name[i] = str[i];
    }
    name[i] = '\0';
    return name;
}

void fill_next(room_t **next, int nb)
{
    for (int i = 0; i < nb; i++) {
        next[i] = NULL;
    }
}

room_t *init_room(char **input, int i)
{
    int nb = find_room(input, i);
    room_t *room = malloc(sizeof(room_t));
    if (room == NULL)
        return NULL;
    room->name = get_room_name(input[nb]);
    if (room->name == NULL)
        return NULL;
    room->x = find_x(input[nb]);
    room->y = find_y(input[nb]);
    room->start = is_start(input, nb);
    room->end = is_end(input, nb);
    room->nb_next = get_nb_next(input, room);
    room->next = malloc(sizeof(room_t *) * (room->nb_next + 1));
    fill_next(room->next, room->nb_next);
    room->is_visited = false;
    room->have_ant = false;
    return room;
}
