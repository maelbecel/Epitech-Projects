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

// Ex 04-1
unsigned int map_get_size (map_t map)
{
    unsigned int size = 0;
    while (map != NULL) {
        size++;
        map = map->next;
    }
    return size;
}

// Ex 04-2
bool map_is_empty (map_t map)
{
    return (map == NULL);
}

// Ex 04-3
bool check_map(map_t *map_ptr, map_t new)
{
    if (*map_ptr == NULL) {
        *map_ptr = new;
        return true;
    }
    return false;
}

bool map_add_elem(map_t *map_ptr, void *key, void *value,
                    key_comparator_t key_cmp )
{
    map_t tmp = *map_ptr;
    map_t new = malloc(sizeof(*new));
    pair_t *temp = NULL;
    pair_t *pair = malloc(sizeof(pair_t));
    pair->key = key;
    pair->value = value;
    if (new == NULL)
        return false;
    new->value = pair;
    new->next = NULL;
    if (check_map(map_ptr, new))
        return true;
    while (tmp->next != NULL) {
        temp = (pair_t *)tmp->value;
        if (key_cmp(temp->key, key) == 0)
            return false;
        tmp = tmp->next;
    }
    tmp->next = new;
    return true;
}

// Ex 04-4
void * map_get_elem(map_t map, void *key, key_comparator_t key_cmp)
{
    pair_t *pair = NULL;
    while (map != NULL) {
        pair = (pair_t *)map->value;
        if (key_cmp(pair->key, key) == 0)
            return pair->value;
        map = map->next;
    }
    return NULL;
}
