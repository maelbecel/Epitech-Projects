/*
** EPITECH PROJECT, 2021
** my_apply_on_matching_nodes.c
** File description:
** xxx
*/

#include "include/mylist.h"

int my_apply_on_matching_nodes (linked_list_t * begin , int (* f )(),
                                void const * data_ref, int(*cmp)()){
    while (begin->next != NULL) {
        if (cmp(begin->list, data_ref)) {
            (*f)(begin->list);
        }
        begin = begin->next;
    }
}
