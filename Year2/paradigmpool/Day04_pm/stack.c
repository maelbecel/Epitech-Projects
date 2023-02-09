/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "list.h"
#include "stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Ex 02-1
unsigned int stack_get_size(stack_t stack)
{
    unsigned int size = 0;
    while (stack != NULL) {
        size++;
        stack = stack->next;
    }
    return size;
}

// Ex 02-2
bool stack_is_empty(stack_t stack)
{
    return (stack == NULL);
}

// Ex 02-3
bool stack_push(stack_t *stack_ptr, void *elem)
{
    list_t new = malloc(sizeof(node_t));
    if (new == NULL)
        return false;
    new->value = elem;
    new->next = *stack_ptr;
    *stack_ptr = new;
    return true;
}

// Ex 02-4
bool stack_pop(stack_t *stack_ptr)
{
    list_t tmp = *stack_ptr;
    if (*stack_ptr == NULL)
        return false;
    *stack_ptr = (*stack_ptr)->next;
    free(tmp);
    return true;
}

// Ex 02-5
void stack_clear(stack_t *stack_ptr)
{
    while (*stack_ptr != NULL)
        stack_pop(stack_ptr);
}
