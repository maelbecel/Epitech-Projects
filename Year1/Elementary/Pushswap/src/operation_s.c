/*
** EPITECH PROJECT, 2021
** operation.c
** File description:
** op
*/

#include "pushswap.h"
#include "my.h"
#include "printf.h"
#include <stdlib.h>

void sa(chainedlist_t *list_a)
{
    write(1,"sa ",3);
    swapnode(list_a->first);
}

void sb(chainedlist_t *list_b)
{
    write(1,"sb ",3);
    swapnode(list_b->first);
}

void sc(chainedlist_t *list_a, chainedlist_t *list_b)
{
    swapnode(list_a->first);
    swapnode(list_b->first);
}
