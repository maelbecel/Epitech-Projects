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

// Ex 00-1
unsigned int int_list_get_size(int_list_t list)
{
    int_list_t tmp = list;
    unsigned int size = 0;

    while (tmp != NULL) {
        size++;
        tmp = tmp->next;
    }
    return size;
}

// Ex 00-2
bool int_list_is_empty(int_list_t list)
{
    return (list == NULL);
}

//Ex 00-3
void int_list_dump(int_list_t list)
{
    int_list_t tmp = list;

    while (tmp != NULL) {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}

// Ex 00-4
bool int_list_add_elem_at_front(int_list_t *front_ptr, int elem)
{
    int_list_t new;

    if (!front_ptr)
        return false;
    new = malloc(sizeof(*new));
    new->value = elem;
    new->next = *front_ptr;
    *front_ptr = new;
    return true;
}

// Ex 00-5
bool int_list_add_elem_at_back(int_list_t *front_ptr, int elem)
{
    int_list_t new;
    int_list_t tmp;

    if (!*front_ptr)
        return false;
    tmp = *front_ptr;
    new = malloc(sizeof(*new));
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
