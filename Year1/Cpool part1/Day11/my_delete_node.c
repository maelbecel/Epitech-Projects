/*
** EPITECH PROJECT, 2021
** my_delete_nodes
** File description:
** xxx
*/

#include "include/mylist.h"

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    linked_list_t *tmp = begin;

    while (tmp != NULL) {
        if (tmp != NULL && cmp(tmp->list, data_ref) == 0) {
            *begin = tmp->next;
        }
        tmp = tmp->next;
    }
    return (0);
}
