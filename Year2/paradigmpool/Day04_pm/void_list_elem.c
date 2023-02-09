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

// Ex 01-1
unsigned int list_get_size(list_t list)
{
    unsigned int size = 0;
    while (list != NULL) {
        size++;
        list = list->next;
    }
    return size;
}

// Ex 01-2
bool list_is_empty(list_t list)
{
    if (list == NULL)
        return true;
    return false;
}

// Ex 01-3
bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    list_t new = malloc(sizeof(node_t));
    if (new == NULL)
        return false;
    new->value = elem;
    new->next = *front_ptr;
    *front_ptr = new;
    return true;
}

// Ex 01-4
bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    list_t new = malloc(sizeof(node_t));
    list_t tmp = *front_ptr;
    if (new == NULL)
        return false;
    new->value = elem;
    new->next = NULL;
    if (*front_ptr == NULL) {
        *front_ptr = new;
        return true;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    return true;
}

// Ex 01-5
bool list_add_elem_at_position( list_t *front_ptr, void *elem, unsigned int pos)
{
    list_t new = malloc(sizeof(node_t));
    list_t tmp = *front_ptr;
    if (new == NULL)
        return false;
    new->value = elem;
    if (pos == 0)
        return list_add_elem_at_front(front_ptr, elem);
    if (pos > list_get_size(*front_ptr))
        return list_add_elem_at_back(front_ptr, elem);
    for (unsigned int i = 0; i < pos - 1; i++)
        tmp = tmp->next;
    new->next = tmp->next;
    tmp->next = new;
    return true;
}
