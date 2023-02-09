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

// Ex 03-6
void *queue_front(queue_t queue)
{
    if (queue == NULL)
        return NULL;
    return queue->value;
}
