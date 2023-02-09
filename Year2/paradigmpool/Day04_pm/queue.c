/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "list.h"
#include "queue.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Ex 03-1
unsigned int queue_get_size(queue_t queue)
{
    unsigned int size = 0;
    while (queue != NULL) {
        size++;
        queue = queue->next;
    }
    return size;
}

// Ex 03-2
bool queue_is_empty(queue_t queue)
{
    return (queue == NULL);
}

// Ex 03-3
bool queue_push(queue_t *queue_ptr, void *elem)
{
    list_t new = malloc(sizeof(node_t));
    if (new == NULL)
        return false;
    new->value = elem;
    new->next = NULL;
    if (*queue_ptr == NULL)
        *queue_ptr = new;
    else {
        list_t tmp = *queue_ptr;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
    return true;
}

// Ex 03-4
bool queue_pop(queue_t *queue_ptr)
{
    list_t tmp = *queue_ptr;
    if (*queue_ptr == NULL)
        return false;
    *queue_ptr = (*queue_ptr)->next;
    free(tmp);
    return true;
}

// Ex 03-5
void queue_clear(queue_t *queue_ptr)
{
    while (*queue_ptr != NULL)
        queue_pop(queue_ptr);
}
