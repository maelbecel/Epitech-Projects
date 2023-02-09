/*
** EPITECH PROJECT, 2021
** my_list_size
** File description:
** x
*/

#include "include/mylist.h"

void my_rev_list ( linked_list_t ** begin )
{
    linked_list_t *b;
    linked_list_t *temp;
    linked_list_t *tnext;

    b = *begin;
    temp = 0;
    while (b->next) {
        tnext = b->next;
        b->next = temp;
        temp = b;
        b = tnext;
    }
    b->next = temp;
    *begin = b;
}
