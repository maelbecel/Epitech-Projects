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

// Ex 01-6
void * list_get_elem_at_front(list_t list)
{
    if (list == NULL)
        return NULL;
    return list->value;
}

// Ex 01-7
void * list_get_elem_at_back(list_t list)
{
    if (list == NULL)
        return NULL;
    while (list->next != NULL)
        list = list->next;
    return list->value;
}

// Ex 01-8
void * list_get_elem_at_position(list_t list, unsigned int position)
{
    if (list == NULL)
        return NULL;
    for (unsigned int i = 0; i < position; i++) {
        if (list->next == NULL)
            return NULL;
        list = list->next;
    }
    return list->value;
}

// Ex 01-9
bool list_del_elem_at_front(list_t *front_ptr)
{
    list_t tmp = *front_ptr;
    if (*front_ptr == NULL)
        return false;
    *front_ptr = (*front_ptr)->next;
    free(tmp);
    return true;
}

// Ex 01-10
bool list_del_elem_at_back(list_t *front_ptr)
{
    list_t tmp = *front_ptr;
    if (*front_ptr == NULL)
        return false;
    if ((*front_ptr)->next == NULL) {
        free(*front_ptr);
        *front_ptr = NULL;
        return true;
    }
    while (tmp->next->next != NULL)
        tmp = tmp->next;
    free(tmp->next);
    tmp->next = NULL;
    return true;
}
