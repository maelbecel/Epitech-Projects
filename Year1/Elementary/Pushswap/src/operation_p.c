/*
** EPITECH PROJECT, 2021
** operation_p
** File description:
** operation_p.c
*/

#include "pushswap.h"
#include "my.h"
#include "printf.h"
#include <stdlib.h>

void paend(chainedlist_t *list_a, chainedlist_t *list_b, int n)
{
    for (int i = 0; i < n; i++){
        write(1,"pa",2);
        node_t *temp = malloc(sizeof(node_t));
        temp->data = list_b->first->data;
        temp->suiv = list_a->first;
        temp->prec = NULL;
        list_a->first->prec = temp;
        list_a->first = temp;
        delfirst(list_b);
        list_a->size++;
        list_b->size--;
    }
}

void pa(chainedlist_t *list_a, chainedlist_t *list_b, int n)
{
    for (int i = 0; i < n; i++){
        write(1,"pa ",3);
        node_t *temp = malloc(sizeof(node_t));
        temp->data = list_b->first->data;
        temp->suiv = list_a->first;
        temp->prec = NULL;
        list_a->first->prec = temp;
        list_a->first = temp;
        delfirst(list_b);
        list_a->size++;
        list_b->size--;
    }
}

void pb(chainedlist_t *list_a, chainedlist_t *list_b, int n)
{
    for (int i = 0; i < n; i++){
        write(1,"pb ",3);
        node_t *temp = malloc(sizeof(node_t));
        temp->data = list_a->first->data;
        temp->suiv = list_b->first;
        temp->prec = NULL;
        list_b->first->prec = temp;
        list_b->first = temp;
        delfirst(list_a);
        list_b->size++;
        list_a->size--;
    }
}