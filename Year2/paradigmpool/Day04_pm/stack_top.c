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

// Ex 02-6
void *stack_top(stack_t stack)
{
    if (stack == NULL)
        return NULL;
    return stack->value;
}
