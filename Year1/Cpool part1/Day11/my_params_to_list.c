/*
** EPITECH PROJECT, 2021
** my_params_to_list
** File description:
** x
*/

#include "include/mylist.h"

linked_list_t * my_params_to_list (int ac , char * const * av )
{
    linked_list_t *list;
    linked_list_t *element;
    element = malloc(sizeof(linked_list_t *));
    list = NULL;

    for (int i = 0; i <= ac ; i++){
        element->list = av[i];
        element->next = list;
        list = element;
    }
    return list;
}
