/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "int_list.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Ex 00-6
bool int_list_add_elem_at_position(int_list_t *front_ptr, int elem,
                                    unsigned int position)
{
    int_list_t new;
    int_list_t tmp;
    if (!front_ptr)
        return false;
    new = malloc(sizeof(*new));
    tmp = *front_ptr;
    new->value = elem;
    if (position == 0) {
        new->next = *front_ptr;
        *front_ptr = new;
        return true;
    }
    for (unsigned int i = 0; i < position - 1; i++) {
        if (tmp == NULL)
            return false;
        tmp = tmp->next;
    }
    new->next = tmp->next;
    tmp->next = new;
    return true;
}

// Ex 00-7
int int_list_get_elem_at_front(int_list_t list)
{
    return (list == NULL) ? 0 : list->value;
}

// Ex 00-8
int int_list_get_elem_at_back(int_list_t list)
{
    int_list_t tmp = list;
    if (tmp == NULL)
        return 0;
    while (tmp->next != NULL)
        tmp = tmp->next;
    return tmp->value;
}

// Ex 00-9
int int_list_get_elem_at_position(int_list_t list, unsigned int position)
{
    int_list_t tmp = list;

    for (unsigned int i = 0; i < position; i++) {
        if (tmp == NULL)
            return 0;
        tmp = tmp->next;
    }
    return tmp->value;
}

// Ex 00-10
bool int_list_del_elem_at_front(int_list_t *front_ptr)
{
    int_list_t pointer;

    if (front_ptr == NULL)
        return false;
    pointer = *front_ptr;
    (*front_ptr) = (*front_ptr)->next;
    free(pointer);
    return true;
}
