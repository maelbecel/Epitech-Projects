/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool list_del_elem_at_front(list_t *front_ptr);


// Ex 01-11
bool verif_pos(list_t tmp, unsigned int position)
{
    for (unsigned int i = 0; i < position; i++) {
        if (tmp->next == NULL)
            return false;
        tmp = tmp->next;
    }
    return true;
}

bool list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    list_t tmp = *front_ptr;
    list_t tmp2 = *front_ptr;
    if (*front_ptr == NULL)
        return false;
    if (position == 0) {
        *front_ptr = (*front_ptr)->next;
        free(tmp);
        return true;
    }
    if (!verif_pos(tmp, position))
        return false;
    for (unsigned int i = 0; i < position - 1; i++) {
        if (tmp2->next == NULL)
            return false;
        tmp2 = tmp2->next;
    }
    tmp2->next = tmp->next;
    free(tmp);
    return true;
}

// Ex 01-12
void list_clear(list_t * front)
{
    while (*front != NULL)
        list_del_elem_at_front(front);
}

// Ex 01-13
void list_dump(list_t list, value_displayer_t val_disp)
{
    while (list != NULL) {
        val_disp(list->value);
        list = list->next;
    }
}
