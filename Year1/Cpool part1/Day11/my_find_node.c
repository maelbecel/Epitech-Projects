/*
** EPITECH PROJECT, 2021
** my_find_node
** File description:
** xxx
*/

#include "include/mylist.h"

linked_list_t   *my_find_node(linked_list_t const *begin,
                            void const *data_ref, int (*cmp)())
{
    while (begin != NULL) {
        if (cmp(begin->list, data_ref) == 0)
            return (begin);
        begin = begin->next;
    }
    return (NULL);
}
