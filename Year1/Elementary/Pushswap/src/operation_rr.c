/*
** EPITECH PROJECT, 2021
** operation_r.c
** File description:
** operation r
*/

#include "pushswap.h"
#include "my.h"
#include "printf.h"
#include <stdlib.h>

void rra(chainedlist_t *list_a, int n)
{
    for (int i = 0; i < n; i++){
        write(1,"rra ",4);
        node_t *temp = malloc(sizeof(node_t));
        temp->data = list_a->last->data;
        temp->suiv = list_a->first;
        temp->prec = NULL;
        list_a->last = list_a->last->prec;
        list_a->last->suiv = NULL;
        list_a->first->prec = temp;
        list_a->first = temp;
    }
}

void rrb(chainedlist_t *list_b, int n)
{
    for (int i = 0; i < n; i++){
        write(1,"rrb ",4);
        node_t *temp = malloc(sizeof(node_t));
        temp->data = list_b->last->data;
        temp->suiv = list_b->first;
        temp->prec = NULL;
        list_b->last = list_b->last->prec;
        list_b->last->suiv = NULL;
        list_b->first->prec = temp;
        list_b->first = temp;
    }
}

void rrr(chainedlist_t *list_a, chainedlist_t *list_b, int n)
{
    rra(list_a, n);
    rrb(list_b, n);
}