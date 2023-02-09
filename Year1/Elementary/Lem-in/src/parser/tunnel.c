/*
** EPITECH PROJECT, 2022
** B-CPE-200-REN-2-1-lemin-lucas.iglesia
** File description:
** tunnel
*/

#include "my.h"
#include "printf.h"
#include "lemin.h"

bool is_link(char *input)
{
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '-')
            return true;
    }
    return false;
}

char *get_name(char *input)
{
    int size = my_strlen(input);
    char *name = malloc(sizeof(char) * (size + 1));
    int i = 0;

    if (name == NULL)
        return NULL;
    for (; input[i] != '-'; i++) {
        name[i] = input[i];
    }
    name[i] = '\0';
    return name;
}

bool is_nb_next(char *input, room_t *room)
{
    if (my_strcmp(room->name, get_name(input)) == 0) {
        return true;
    }
    if (my_strncmp(room->name, get_second_name(input),
                                                my_strlen(room->name)) == 0){
        return true;
    }
    return false;
}

int get_nb_next(char **input, room_t *room)
{
    int nb = 0;
    for (int i = 0; input[i] != NULL; i++) {
        if (is_link(input[i])) {
            nb += is_nb_next(input[i], room);
        }
    }
    return nb;
}
