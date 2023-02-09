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

void ra(chainedlist_t *list_a, int n)
{
    for (int i = 0; i < n; i++) {
        write(1,"ra ",3);
        node_t *temp = malloc(sizeof(node_t));
        temp->data = list_a->first->data;
        temp->suiv = NULL;
        temp->prec = list_a->last;
        list_a->last->suiv = temp;
        list_a->last = temp;
        delfirst(list_a);
    }
}

void rb(chainedlist_t *list_b, int n)
{
    for (int i = 0; i < n; i++) {
        write(1,"rb ",3);
        node_t *temp = malloc(sizeof(node_t));
        temp->data = list_b->first->data;
        temp->suiv = NULL;
        temp->prec = list_b->last;
        list_b->last->suiv = temp;
        list_b->last = temp;
        delfirst(list_b);
    }
}

void rr(chainedlist_t *list_a, chainedlist_t *list_b, int n)
{
    ra(list_a, n);
    rb(list_b, n);
}