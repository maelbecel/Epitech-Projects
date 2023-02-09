/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-lemin-lucas.iglesia
** File description:
** init
*/

#include "my.h"
#include "printf.h"
#include "lemin.h"

bool is_room(char *input)
{
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ')
            return true;
    }
    return false;
}

int count_room(char **input)
{
    int nb = 0;

    for (int i = 1; input[i]; i++) {
        if (input[i][0] != '#') {
            nb = is_room(input[i]) ? nb + 1 : nb;
        }
    }
    return nb;
}

room_t **init_rooms(char **input, int size)
{
    room_t **room = malloc(sizeof(room_t *) * (size + 1));

    if (room == NULL)
        return NULL;
    for (int i = 0; i < size; i++) {
        room[i] = init_room(input, i);
        if (room[i] == NULL)
            return NULL;
    }
    room[size] = NULL;
    return room;
}

lemin_t *init_lemin(void)
{
    lemin_t *lemin = malloc(sizeof(lemin_t));

    if (lemin == NULL)
        return NULL;
    lemin->input = read_input();
    if (lemin->input == NULL)
        return NULL;
    lemin->nbr_ant = my_getnbr(lemin->input[0]);
    if (lemin->nbr_ant == 0 && my_strlen(lemin->input[0]) != 1)
        return NULL;
    lemin->size = count_room(lemin->input);
    lemin->room = init_rooms(lemin->input, lemin->size);
    if (lemin->room == NULL || init_tunnel(lemin->input, lemin->room) == 84)
        return NULL;
    lemin->start = find_start(lemin->room);
    lemin->end = find_end(lemin->room);
    return lemin;
}
