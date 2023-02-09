/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "list.h"
#include "map.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Ex 04-5
bool map_del_elem(map_t *map_ptr, void *key, key_comparator_t key_cmp)
{
    map_t tmp = *map_ptr;
    map_t pointer = *map_ptr;
    pair_t *temp = NULL;

    if (tmp == NULL)
        return false;
    if (key_cmp(((pair_t *)tmp->value)->key, key) == 0) {
        *map_ptr = tmp->next; free(tmp);
        return true;
    }
    while (tmp->next != NULL) {
        temp = (pair_t *)tmp->value;
        if (key_cmp(temp->key, key) == 0) {
            pointer->next = tmp->next; free(tmp);
            return true;
        }
        pointer = tmp;
        tmp = tmp->next;
    }
    return false;
}

// Ex 04-6
void map_clear(map_t *map_ptr)
{
    map_t pointer = *map_ptr;

    while (pointer != NULL) {
        *map_ptr = pointer->next;
        if (pointer->value != NULL)
            free(pointer->value);
        free(pointer);
        pointer = *map_ptr;
    }
}
