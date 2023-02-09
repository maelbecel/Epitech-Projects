/*
** EPITECH PROJECT, 2021
** my_list_size
** File description:
** x
*/

#include "include/mylist.h"

int my_list_size ( linked_list_t const * begin )
{
    int len = 0;
    struct linked_list_t *list;

    x = list;
    while (x != NULL) {
        len++;
        x = x->next;
    }
    return (len);
}
