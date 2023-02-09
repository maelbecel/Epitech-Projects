/*
** EPITECH PROJECT, 2021
** my_list_size
** File description:
** x
*/

#include "include/mylist.h"

int my_apply_on_nodes(linked_list_t * begin, int (* f) (void *))
{
    linked_list_t * x;

    x = begin;
    while (x != NULL) {
        f(l->list);
        x = x->next;
    }
    return 0;
} 
