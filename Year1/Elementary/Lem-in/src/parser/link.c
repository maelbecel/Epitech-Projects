/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-lemin-lucas.iglesia
** File description:
** link
*/

#include "my.h"
#include "printf.h"
#include "lemin.h"

char *get_second_name(char *input)
{
    int size = my_strlen(input);
    int i = 0;
    int j = 0;
    char *name = malloc(sizeof(char) * (size + 1));

    if (name == NULL)
        return NULL;
    for (; input[i] != '-'; i++);
    i++;
    for (; input[i] != '\0'; i++) {
        name[j++] = input[i];
    }
    name[j] = '\0';
    return name;
}

room_t *find_next(char *name, room_t **room)
{
    for (int i = 0; room[i] != NULL; i++) {
        if (my_strncmp(name, room[i]->name, my_strlen(room[i]->name)) == 0) {
            return room[i];
        }
    }
    return NULL;
}

static room_t *find_room(char **input, room_t **other, room_t *room, int nb)
{
    room_t *tmp = NULL;
    for (int i = 0; input[i] != NULL; i++) {
        if ((tmp = find_room_pt2(input[i], room, &nb, other)) != NULL) {
            verif_next(tmp, room);
            return tmp;
        }
    }
    return NULL;
}

static void find_tunnel(char **input, room_t **other, room_t *room,
                            room_t **next)
{
    next[room->nb_next] = NULL;
    for (int i = 0; i < room->nb_next; i++) {
        next[i] = find_room(input, other, room, i);
    }
}

int init_tunnel(char **input, room_t **room)
{
    for (int i = 0; room[i] != NULL; i++) {
        find_tunnel(input, room, room[i], room[i]->next);
        if (room[i]->next == NULL)
            return 84;
    }
    return 0;
}
