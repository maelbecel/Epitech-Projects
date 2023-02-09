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

// Ex 00-11
bool int_list_del_elem_at_back(int_list_t *front_ptr)
{
    int_list_t pointer;
    int_list_t tmp;

    if (*front_ptr == NULL)
        return false;
    tmp = *front_ptr;
    pointer = tmp;
    if (tmp->next == NULL) {
        tmp = NULL;
        return true;
    }
    while (pointer->next->next != NULL)
        pointer = pointer->next;
    free(pointer->next);
    pointer->next = NULL;
    return true;
}

// Ex 00-12
bool int_list_del_elem_at_position(int_list_t *front_ptr, unsigned int position)
{
    int_list_t *pointer;

    if (front_ptr == NULL)
        return false;
    pointer = front_ptr;
    if (position == 0) {
        *front_ptr = (*front_ptr)->next;
        return true;
    }
    for (unsigned int i = 0; i < position; i++) {
        if (*front_ptr == NULL)
            return false;
        pointer = front_ptr;
        *front_ptr = (*front_ptr)->next;
    }
    free((*pointer)->next);
    (*pointer)->next = (*front_ptr)->next;
    return true;
}

// Ex 00-13
void int_list_clear(int_list_t *front_ptr)
{
    int_list_t pointer;

    if (front_ptr == NULL)
        return;
    pointer = *front_ptr;
    while (pointer != NULL) {
        *front_ptr = pointer->next;
        free(pointer);
        pointer = *front_ptr;
    }
}
